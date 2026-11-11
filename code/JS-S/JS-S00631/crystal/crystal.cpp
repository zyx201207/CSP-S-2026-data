#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define all(v) v.begin(),v.end()
#define lowbit(x) (x&-x)
#define pll pair<ll,ll>
const int N = 5e5+5, mod = 998244353;
int a[N],res,q[N];
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    int l=1;
    rep(i,1,n) {
        q[i]=q[i-1]+a[i];
        while(a[i]*(i-l+1)-(q[i]-q[l-1])>m) ++l;
        res=max(res,i-l+1);
    } cout<<res<<'\n';
    return 0;
}
/*
remember freopen
long long
initialize
*/