#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int rd(){
    int x=0,f=0;char c=getchar();
    while(!isdigit(c)) f=(c=='-'),c=getchar();
    while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return f?-x:x;
}
const int N=5e5+10;
int n,a[N],s[N],m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=rd();m=rd();
    for(int i=1;i<=n;i++) a[i]=rd();
    sort(a+1,a+n+1);
    int res=1;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        int l=1,r=i,ans=i;
        // printf("%lld %lld\n",i*a[i]-s[i]-m,m);
        while(l<=r){
            int mid=(l+r)>>1;
            if(((i-mid+1)*a[i]-(s[i]-s[mid-1]))<=m) ans=mid,r=mid-1;
            else l=mid+1;
        }
        // if((i-ans+1)==n) printf("%lld %lld %lld\n",a[i],m,i);
        res=max(res,i-ans+1);
    }
    // int sum=0;
    // for(int i=1;i<=n;i++) sum+=(a[n]-a[i]);
    // // printf("%lld %lld\n",m-sum,m-(n*a[n]-s[n]));
    printf("%lld",res);
}