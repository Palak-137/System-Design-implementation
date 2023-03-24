#### sliding window rate limiter

A rate limiter restricts the intended or unintended excessive usage of a system by regulating the number of requests made to/from it
by discarding the surplus ones. In this article, we dive deep into an intuitive and heuristic approach for rate-limiting that uses a sliding window. 
The other algorithms and approaches include Leaky Bucket, Token Bucket and Fixed Window.

Rate limiting is usually applied per access token or per user or per region/IP. For a generic rate-limiting system that we intend to design here, 
this is abstracted by a configuration key key on which the capacity (limit) will be configured; the key could hold any of the aforementioned value or its combinations.
The limit is defined as the number of requests number_of_requests allowed within a time window time_window_sec (defined in seconds).

#### The algorithm 
The algorithm is pretty intuitive and could be summarized as follow
If the number of requests served on configuration key key in the last time_window_sec seconds is more than number_of_requests configured for it then discard, 
else the request goes through while we update the counter.
Although the above description of the algorithm looks very close to the core definition of any rate limiter, 
it becomes important to visualize what is happening here and implement it in an extremely efficient and resourceful manner.

We assume that all the request coming in the uniform rate hence ingoring the spike in the requests. 

#### The implementation 

This implementation uses an array to store the counts of requests within the window, and a circular buffer to keep track of the oldest index in the window. 
The implementation is based on the sliding window counter algorithm, which tracks the sum of counts within the window and decrements the count at the oldest 
index to slide the window forward.

Resources:

[Video explaination](https://www.youtube.com/watch?v=Ph9odgg8wQ0&ab_channel=CoreDump)

[Blog](https://arpitbhayani.me/blogs/sliding-window-ratelimiter)



