# Exponential-Backoff-Rate-Limiter

One-line description: A C++ class implementing rate limiting with exponential backoff for operations that may be rate-limited.

Summary: This C++ class, `RateLimiter`, handles operations that may be subject to rate limiting by implementing an exponential backoff strategy. It attempts an operation up to a specified maximum number of retries (5 retries). If the operation is rate-limited, the class waits for an increasing amount of time before retrying, starting from 1 second and potentially growing up to a maximum of 120 seconds, increasing by a factor of 2 after each retry. The class outputs messages indicating the operation's success or if it has been rate-limited, and it sleeps for the calculated backoff period using `std::this_thread::sleep_for` from the `<thread>` library to manage the delay. If the maximum number of retries is reached without success, it notifies the user that the operation has failed.
