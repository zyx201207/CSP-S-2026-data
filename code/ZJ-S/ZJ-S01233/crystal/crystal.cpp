#include<bits/stdc++.h>
#define int long long
#define gc getchar
#define pb push_back
#define vci vector<int>
#define fr(i,l,r) for(int i=l;i<=r;i++)
#define gr(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=5e5+10;
inline int read(){
    int x=0;char ch=gc();bool fg=0;
    while(!isdigit(ch)) fg^=ch=='-',ch=gc();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=gc();
    return fg?~(x-1):x;
}
int n,m,a[N],sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    fr(i,1,n) a[i]=read();
    sort(a+1,a+n+1);
    int ip=0,ans=0;
    fr(i,1,n){
        sum[i]=sum[i-1]+a[i];
        while(a[i]*(i-ip)-(sum[i]-sum[ip])>m) ip++;
        ans=max(ans,i-ip);
    }
    printf("%lld\n",ans);
    return 0;
}