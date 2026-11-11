#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans,a[N],s[N],f[N];
int check(int c,int x){
    int l=1,r=c;
    while(l<=r){
        int mid=l+r>>1;
        int sum=x*(c-mid+1)-(s[c]-s[mid-1]);
        if(sum<=m) r=mid-1;
        else l=mid+1;
    }
    return c-l+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    f[1]=1;
    ans=1;
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        s[i]=s[i-1]+a[i];
        if(a[i]==a[i-1]) f[i]=f[i-1]+1;
        else f[i]=check(i,a[i]);
        ans=max(ans,f[i]);
    }
    printf("%lld",ans);
    return 0;
}
