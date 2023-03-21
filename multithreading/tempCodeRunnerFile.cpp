#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

void solve(){

}

int main(){
   const int n = 90000;
    bool primes[n+1];
    for(int i = 0; i <= n; i++) {
        primes[i] = true;
    }
    primes[0] = false;
    primes[1] = false;
    auto start = chrono::high_resolution_clock::now(); // start the timer
    for(int i = 2; i*i <= n; i++) {
        if(primes[i]) {
            for(int j = i*i; j <= n; j += i) {
                primes[j] = false;
            }
        }
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