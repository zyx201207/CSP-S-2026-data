#include<bits/stdc++.h>
#define CSP2026 using
#define RP namespace
#define PLUSPLUS std
CSP2026 RP PLUSPLUS;
using ll=long long;
#define debug(x) cout<<"clock="<<clock()<<' '<<#x<<'='<<(x)<<'\n'
inline int rd(){int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);return x*f;}
inline ll rdll(){ll x=0;int f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);return x*f;}
constexpr int N=5e5+5;
int a[N];
ll pre[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n=rd(),mx=0;
    ll m=rdll();
    for(int i=1;i<=n;++i)a[i]=rd();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;++i){
        int l=1,r=i,ans=r;
        while(l<=r){
            int mid=(l+r)>>1;
            ll p=1ll*(i-mid+1)*a[i]-(pre[i]-pre[mid-1]);
            if(p<=m)ans=mid,r=mid-1;
            else l=mid+1;
        }mx=max(mx,i-ans+1);
    }cout<<mx<<'\n';
}