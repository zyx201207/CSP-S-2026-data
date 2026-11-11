#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define INF 0x3f3f3f3f
#define endl '\n'
// #define int ll
using namespace std;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0' or ch>'9') {if (ch=='-') f=-f;ch=getchar();}
    while (ch>='0' and ch<='9') x=x*10+(ll)(ch-'0'),ch=getchar();
    return x*f;
}
ll gcd(ll x,ll y){
    if (y==0) return x;
    return gcd(y,x%y);
}
ll qpow(ll x,ll y,ll mod){
    ll ans=1;
    if (mod==-1) mod=1e18;
    while (y){
        if (y&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return ans;
}
const int N=5e5;
int n;
ll m,a[N+5],s[N+5];
bool check(int l,int r){
    ll sum=s[r]-s[l-1],len=r-l+1;
    return a[r]*len<=sum+m;
}
void solve(){
    n=read(),m=read();
    for (int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for  (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    ll maxx=1;
    for (int i=1;i<=n;i++){
        int l=1,r=i,ans=i;
        while (l<=r){
            int mid=(l+r)>>1;
            if (check(mid,i)) r=mid-1,ans=mid;
            else l=mid+1;
        }
        maxx=max(maxx,1ll*i-ans+1);
    }
    printf("%lld\n",maxx);
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll t=1;
    while (t--) solve();
    return 0;
}