#include<bits/stdc++.h>
#define ll long long
#define mxn 2000003
#define md 998244353
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rept(i,a,b) for(int i=(a);i<(b);++i)
#define drep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline ll read(){
    ll x=0;bool fl=0;char c=getchar();
    while(!isdigit(c)){if(c=='-')fl=1;c=getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return fl?-x:x;
}
int T,n,p[mxn],f[mxn][2][2];
ll d,ans,a[mxn];
void solve(){
    n=read(),d=read();
    rep(i,1,n)a[i]=read();
    rep(i,1,n)p[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
    rep(i,1,n)f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=0;
    ans=0;
    rep(i,1,n)if(p[i]>i){
        f[p[i]][0][0]++;
        bool b1=i>1&&a[p[i]]-a[i-1]<=d,b2=i>2&&a[p[i]]-a[i-2]<=d;
        if(!b2){
            if(b1)f[p[i]][1][i>1&&a[p[i]-1]-a[i-1]<=d]+=f[i][0][0];
            else f[p[i]][0][i>1&&a[p[i]-1]-a[i-1]<=d]+=f[i][0][0]+f[i][0][1];
        }
        if(!b1){
            f[p[i]][1][i>1&&a[p[i]-1]-a[i-1]<=d]+=f[i][1][0]+f[i][1][1];
        }
        if(i==1)continue;
        int l=max(i<=2?0:p[i-2]+1,i+1),r=p[i-1];
        if(l<=r)ans+=f[i][0][0]*(r-l+1ll);
        l=max(p[i-1]+1,i+1),r=p[i];
        if(l<=r)ans+=(f[i][1][0]+f[i][1][1])*(r-l+1ll);
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read(),T=read();
    while(T--)solve();
    return 0;
}