#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#define int long long
using namespace std;

const int n = 100000;
const int num_threads = 10; // number of threads to use

bool is_prime(int n)
{
    // Check if a number is prime
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n + 1; i++)
        if (n % i == 0)
            return false;
    return true;
}

void find_primes(int start, int end,int &count, mutex& mtx) {
    for(int i = start; i <= end; i++) {
        mtx.lock();
        if(is_prime(i)){
            count++;
        }
         mtx.unlock();
    }
}

signed main() {
    vector<bool> primes(n+1, true);
    primes[0] = false;
    primes[1] = false;
    vector<thread> threads;
    mutex mtx;
    int count = 1;

    auto start = chrono::high_resolution_clock::now(); // start the timer
    int chunk_size = n / num_threads;
    for(int i = 0; i < num_threads; i++) {
        int start_idx = i * chunk_size + 2;
        int end_idx = (i == num_threads-1) ? n : (i+1) * chunk_size - 1;
        threads.emplace_back(find_primes, start_idx, end_idx, ref(count), ref(mtx));
    }
    for(auto& t : threads) {
        t.join();
    }
    

    auto end = chrono::high_resolution_clock::now(); // end the timer
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // calculate the duration
    cout << "There are " << count << " prime numbers up to " << n << endl;
    cout << "Time taken by the program: " << duration.count() << " microseconds" << endl; // print the duration in microseconds
    return 0;
}
