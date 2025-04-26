#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef vector<ppi> vppi;
typedef map<int,int> mii;
typedef map<int,vi> mvi;
typedef map<pii,int> mpi;

// Fast IO-FastIO , M25-Min_25 , Dinic Flow-DinicFlow , Fast Factorize-FFactorize , Brent Factor-BrentFactor , X-Dictionary-XDict
// Beginner FastIO-BFastIO , Pragmas-Prgama , Z-Algorithm-Z-Algorithm , Z-Function-Z-Func , Modular Integer-modular_int


const int INF = 1e9 + 7;
const ll LLINF = 1e18;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
// const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
 
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
 
template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >;

/*/---------------------------IO(Debugging)----------------------/*/
 
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
istream& operator >> (istream &is, T_container &v) { 
   for(T &x : v) is >> x; return is;
}
#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 const& value){
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) 
        os << '-';
    else if (T == 0)
        return os << '0';
    for(; T > 0; ++index){
        buffer[index] = static_cast<char>('0' + (T % 10));
        T /= 10;
    }    
    while(index > 0)
        os << buffer[--index];
    return os;
}
istream& operator >> (istream& is, __int128& T){
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-')
        ++index, mul *= -1;
    for(; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;    
    return is;
}
#endif

template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) { 
   return os << '(' << p.first << ", " << p.second << ')'; 
}
 
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
ostream& operator << (ostream &os, const T_container &v) { 
   os << '{'; string sep; 
   for (const T &x : v) os << sep << x, sep = ", "; 
   return os << '}'; 
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{"; string sep;
    while(!U.empty()){
        out << sep << U.front(); sep = ", "; U.pop();
    }
    return (out << "}");
}

/*/---------------------------RNG----------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN,long long r = LLONG_MAX){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) { // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};

/*/--------------------------Debugger----------------------/*/
#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
         int count_open = 0, len = 1;
         for(int k = 1; ; ++k){
            char cur = *(names + k);
            count_open += (cur == '(' ? 1 : (cur == ')' ? -1: 0));
            if (cur == ',' && count_open == 0){
               const char* comma = names + k;
               cerr.write(names, len) << " : " << arg1 << " | ";
               __f(comma + 1, args...);
               return;
            }
            len = (cur == ' ' ? len : k + 1);
         }
    }
#else
    #define trace(...) 1
#endif
 
 
/*/---------------------------Defines----------------------/*/
#define rep3(i, a, b, j) for(int i = a; i < b; i += j)
#define rep2(i, a, b) rep3(i, a, b, 1)
#define rep1(i, a) rep2(i, 0, a)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define REPR(i,a, b) for (int i=(a);i>=(b);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<endl

// #define int long long or use int64_t based on usecase
//if it is integer overflow use pyhton plz
//Read the Qn Properly, your logic is always correct


//Uncomment it if it is Single Test
#define SINGLE_TEST
#define int long long

void solve()
{
  //Be Careful while solving Questions
  int n;cin>>n;
  vector<pii>v;
  map<int,int>mp;
  rep1(i,n){
    int a,b;cin>>a>>b;
    b++;
    v.pb({a,b});
    mp[a]=1;
    mp[b]=1;
  }
  int i=0;
  unordered_map<int,int>mp1;
  unordered_map<int,int>mp2;
  for(auto it:mp){
    i++;
    mp1[it.first]=i;
    mp2[i]=it.first;
  }
  vector<int>vvv(i+1,0);
  int pp=i+1;
 
  for(int i=0;i<n;i++)
  {
    int first=v[i].first;
    //ab isme mera 5 
    int second=v[i].second;
    //ab isme mera 9 so hum ab prefix sum me us position pe jaake value badha denge so 
    vvv[mp1[first]]++;
    vvv[mp1[second]]--;
  }
  int maxi=INT_MIN;
  int ans=0;
  for(int i=0;i<vvv.size();i++){
    ans+=vvv[i];
    maxi=max(maxi,ans);
  }
  d1(maxi);
  //ab a,b mere v me aagaya so 
  //set me dekhlenge and usko supress krdenge
  //vector<pair<int,int>>
}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
    int t = 1;
    #ifndef SINGLE_TEST
        cin >> t;
    #endif
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
    return 0;
}