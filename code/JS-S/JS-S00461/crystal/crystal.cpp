#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll maxs=600000;
struct ppp{
    ll st,en;
};
vector<ppp>v;
ll n,m,a[maxs],sum[maxs],k[maxs],ans=0;
inline ll read(){
    ll a=0;
    char c=getchar();
    bool pd=0;
    while(c<'0'||c>'9'){
        if(c=='-')pd=1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        a=a*10+c-'0';
        c=getchar();
    }
    if(pd==1)a*=-1;
    return a;
}
inline ll p(ll s,ll e){
    return k[e]-(s-1)*a[e]+sum[s-1];
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        k[i]=(i-1)*a[i]-sum[i-1];
    }
    ll l=1,r=1,now;
    while(l<=n&&r<=n){
        now=p(l,r);
        if(now<=m){
            if(l<r){
                ans=max(ans,r-l+1);
            }
            if(r<n&&p(l,r+1)<=m)r++;
            else l++;
        }else{
            if(l==r)r++;
            else l++;
        }
    }
    printf("%lld",ans);
    return 0;
}
