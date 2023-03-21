#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

const int n = 90000;
const int num_threads = 4; // number of threads to use

void find_primes(int start, int end, vector<bool>& primes) {
    for(int i = start; i*i <= end; i++) {
        if(primes[i]) {
            for(int j = i*i; j <= end; j += i) {
                primes[j] = false;
            }
        }
    }
}

int main() {
    vector<bool> primes(n+1, true);
    primes[0] = false;
    primes[1] = false;
    vector<thread> threads;
    auto start = chrono::high_resolution_clock::now(); // start the timer
    int chunk_size = n / num_threads;
    for(int i = 0; i < num_threads; i++) {
        int start_idx = i * chunk_size + 2;
        int end_idx = (i == num_threads-1) ? n : (i+1) * chunk_size - 1;
        threads.emplace_back(find_primes, start_idx, end_idx, ref(primes));
    }
    for(auto& t : threads) {
        t.join();
    }
    int count = 0;
    for(int i = 2; i <= n; i++) {
        if(primes[i]) {
            count++;
        }
    }
    auto end = chrono::high_resolution_clock::now(); // end the timer
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // calculate the duration
    cout << "There are " << count << " prime numbers up to " << n << endl;
    cout << "Time taken by the program: " << duration.count() << " microseconds" << endl; // print the duration in microseconds
    return 0;
}
