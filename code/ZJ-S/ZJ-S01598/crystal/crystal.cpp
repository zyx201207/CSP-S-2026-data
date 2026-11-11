#include<bits/stdc++.h>
#define rep(i, j, k) for(int i=(j); i<=(k); i++)
#define per(i, j, k) for(int i=(j); i>=(k); i--)
#define debug(a...) _debug(#a, a)
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define int long long
using namespace std;
template<class T> void _debug(const char *s, T x){cout<<s<<'='<<x<<endl;}
template<class T, class... Nxt> void _debug(const char *s, T x, Nxt... nxt){
    int d=0;
    while(d||*s!=',') d+=*s=='(', d-=*s==')', cout<<*s++;
    cout<<'='<<x<<',';
    _debug(s+1, nxt...);
}
const int N=5e5+5;
int n, m, a[N], s[N], ans;
int calc(int l, int r){return a[r]*(r-l+1)-(s[r]-s[l-1]);}

signed main(){
    file("crystal");
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    rep(i, 1, n) cin>>a[i];
    sort(a+1, a+n+1);
    rep(i,1, n) s[i]=s[i-1]+a[i];
    for(int i=1, j=1; i<=n; i++){
        while(calc(j, i)>m) j++;
        ans=max(ans, i-j+1);
    }
    cout<<ans;
}