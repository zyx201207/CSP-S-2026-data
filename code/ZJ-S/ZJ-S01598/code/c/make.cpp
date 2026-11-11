#include<bits/stdc++.h>
#define rep(i, j, k) for(int i=(j); i<=(k); i++)
#define per(i, j, k) for(int i=(j); i>=(k); i--)
#define debug(a...) _debug(#a, a)
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
#define int long long
template<class T> void _debug(const char *s, T x){cout<<s<<'='<<x<<endl;}
template<class T, class... Nxt> void _debug(const char *s, T x, Nxt... nxt){
    int d=0;
    while(d||*s!=',') d+=*s=='(', d-=*s==')', cout<<*s++;
    cout<<'='<<x<<',';
    _debug(s+1, nxt...);
}
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
int ri(int l, int r){return uniform_int_distribution<int>(l, r)(rnd);}

const int N=5e5+5;
vector<pair<int, int>> G[N];

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=200;
    cout<<"0 "<<t<<'\n';
    while(t--){
        int n=ri(1, 20), w=20;
        cout<<n<<' '<<ri(1, w)<<'\n';
        vector<int> d;
        rep(i, 1, n) d.emplace_back(ri(0, w));
        sort(d.begin(), d.end());
        rep(i, 0, n-1) d[i]+=i;
        rep(i, 0, n-1) cout<<d[i]<<' ';
        cout<<'\n';
    }
}