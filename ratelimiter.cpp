#include <iostream>
#include <chrono>
#include <thread>

class RateLimiter {
public:
    // Attempts to perform an operation, applying exponential backoff if rate-limited.
    void performOperationWithExponentialBackoff() {
        int retries = 0;
        const int maxRetries = 5; // Maximum number of retries before giving up
        int backoff = 1; // Initial backoff interval in seconds
        const int backoffFactor = 2; // Factor by which the backoff interval increases
        const int maxBackoff = 120; // Maximum backoff interval in seconds

        while (retries < maxRetries) {
            bool isRateLimited = attemptOperation();

            if (!isRateLimited) {
                std::cout << "Operation successful." << std::endl;
                break; // Operation was successful, exit the loop
            }

            // If operation was rate limited, apply exponential backoff
            std::cout << "Rate limit encountered. Waiting for " << backoff << " second(s) before retrying..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(backoff));

            backoff = std::min(backoff * backoffFactor, maxBackoff); // Increase the backoff interval
            retries++;
        }

        if (retries == maxRetries) {
            std::cout << "Maximum retries reached. Operation failed." << std::endl;
        }
    }
};