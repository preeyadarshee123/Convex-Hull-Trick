#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <functional>
#define pb                    push_back
#define ll                    long long
#define ss                       second
#define ff                        first
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define eps                   0.000000001
#define all(c)               (c).begin(),(c).end()
#define present(c,x)         ((c).find(x) != (c).end())
#define cpresent(c,x)        (find(all(c),x) != (c).end())
//#define pi                   pair<int,int>
#define pll                  pair<ll,ll>
#define endl                 '\n'
#define ull                  unsigned long long
using namespace std;
vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}

#define debug(args...) {__evars_begin(__LINE__); __evars(split(#args, ',').begin(), args);}

inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template<typename T> inline void __evars_out_var(vector<T> val) { cerr << arrStr(val, val.size()); }
template<typename T> inline void __evars_out_var(T* val) { cerr << arrStr(val, 10); }
template<typename T> inline void __evars_out_var(T val) { cerr << val; }
inline void __evars(vector<string>::iterator it) { cerr << endl; }

template<typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
    cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
    __evars_out_var(a);
    cerr << "; ";
    __evars(++it, args...);
}
//using namespace __gnu_pbds;
//typedef tree<int, null_type, int>, rb_tree_tag,tree_order_statistics_node_update> policy;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef vector< int > vi;
typedef vector< vi > vvi;
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,-1,1,2,-2,2,-2};
vector<int> vis(200010,0),dis(200010,0),par(500010,0),ed(200010,0);
vector<int> adj[500010];
int myrandom (int i) { return std::rand()%i;}
const int MAX=200010;
const ll inf = 1e9 + 7;
class ConvexHull{
    public :
    vector<vector<ll>> st;
    // st takes { intercept, slope , leftmost_point of the segment , index of the interval in the array }
    void add(ll intercept,ll slope,ll index){
        if(st.empty()){
            st.pb({intercept,slope,-LLONG_MAX,index});
            return ;
        }
        while((int)st.size() > 1){
            vector<ll> x = st.back();
            vector<ll> y = st[(int)st.size()-2];
            ll pt = (y[0] - intercept)/ (slope - y[1]);
            if(pt <= x[2]){
                st.pop_back();
            }
            else{
                break;
            }
        }
        vector<ll> x = st.back();
        ll leftmostPoint = (x[0] - intercept) / (slope - x[1]);
        st.push_back({intercept,slope,leftmostPoint,index});
    }
    ll get(ll point){
        ll lo = -1,hi = (int)st.size();
        while(hi - lo > 1){
            ll mid = (lo+hi)/2;
            if(st[mid][2] <= point){
                lo = mid;
            }
            else{
                hi = mid;
            }
        }
        return st[lo][3];
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream fin;
    //ofstream fout;
    //fin.open("input.txt");
    //fout.open("output.txt");
    //clock_t launch=clock();
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        cin>>b[i];
    }
    ConvexHull c;
    c.add(0,b[0],0);
    vector<ll> dp(n);
    rep(i,1,n){
        ll index = c.get(a[i]);
        dp[i] = dp[index] + b[index] * a[i];
        c.add(dp[i], b[i] , i);
    }
    cout<<dp[n-1]<<endl;
 }