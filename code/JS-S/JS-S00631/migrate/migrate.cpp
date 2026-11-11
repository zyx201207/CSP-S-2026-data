#include<bits/stdc++.h>
using namespace std;
#define int __int128
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define all(v) v.begin(),v.end()
#define lowbit(x) (x&-x)
#define pll pair<ll,ll>
const int N = 2e6+5, mod = 998244353;
int x[N]; ll xx[N];
int pre[N],pro[N];
    ll nn,dd; int n,d;
int numcnt(int a,int b) {
    int lsa=lower_bound(x+1,x+n+1,a)-x;
    int lsb=upper_bound(x+1,x+n+1,b)-x;
    // cout<<"numcnt("<<a<<","<<b<<")="<<lsb<<"-"<<lsa<<"+1="<<lsb-lsa<<'\n';
    return lsb-lsa;
}
void solve() {
    cin>>nn>>dd,n=nn,d=dd;
    rep(i,1,n) cin>>xx[i],x[i]=xx[i];
    rep(i,1,n-1) {
        pre[i]=1;
        rep(j,1,i-1) {
            if(x[j]+d>=x[i+1]) break;
            if(x[j]+d<x[i]) continue;
            pre[i]+=pre[j];
        }
    }
    per(i,n,2) {
        pro[i]=1;
        per(j,n,i+1) {
            if(x[j]-d<=x[i-1]) break;
            if(x[j]-d>x[i]) continue;
            pro[i]+=pro[j];
        }
    }
    int res=0;
    rep(i,1,n) {
        int tt=upper_bound(x+1,x+n+1,x[i]-d*2)-x;
        rep(j,tt,i-2) {
            if(x[i]-x[j]<=d) break;
            int num=numcnt(x[i]-d,x[j]+d);
            if(num==2) res+=pre[j]*pro[i],
            cerr<<(ll)(x[j])<<" "<<(ll)(x[i])<<" "<<(ll)(pre[j])<<" "<<(ll)(pro[i])<<"\n";
            // cout<<(ll)(x[j])<<" "<<(ll)(x[i])<<" "<<(ll)(num)<<"\n";
        }
    } ll rres=res;
    cout<<rres<<'\n';
    // cout<<"textcase over\n";
}
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll c,t; cin>>c>>t;
    while(t--) solve();
    return 0;
}
/*
remember freopen
long long
initialize
*/