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
    int t=1;
    cout<<"13 "<<t<<'\n';
    while(t--){
        int m=100, n=m*2+1, k=ri(2, n);
        cout<<n<<' '<<k<<'\n';
        rep(i, 1, m){
            cout<<i<<' '<<i+1<<'\n';
        }
        rep(i, m+1, n-1){
            cout<<i-m<<' '<<i+1<<'\n';
        }
        cout<<'\n';
    }
}