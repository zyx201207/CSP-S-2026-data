#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL arr[500005],m;
int n;
bool check(int x){
    LL shu=0LL;
    for (int i=1;i<=x;++i){shu+=(arr[x]-arr[i]);}
    if (shu<=m){return 1;}
    for (int i=x+1;i<=n;++i){
        shu-=arr[i-1]-arr[i-x];
        shu+=(arr[i]-arr[i-1])*(LL)(x-1);
        if (shu<=m){return 1;}
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for (int i=1;i<=n;++i){scanf("%lld",arr+i);}
    sort(arr+1,arr+1+n);
    int l=1,r=n,mid,ans=1;
    while (l<=r){
        mid=(l+r)>>1;
        if (check(mid)){ans=mid;l=mid+1;}else{r=mid-1;}
    }
    printf("%d\n",ans);
    return 0;
}
