#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5050505],m,sum[5050505];
int find(int i){
    int l = 1,r = i,mid,ans = 1;
    while(l<=r){
        mid = (l+r)>>1;
        if(a[i]*mid-sum[i]+sum[i-mid]<=m) ans = mid,l = mid+1;
        else r = mid-1;
    }return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i = 1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++) sum[i] = sum[i-1]+a[i];
    int ans = 1;
    for(int i = 1;i<=n;i++) ans = max(ans,find(i));
    printf("%d",ans);
    return 0;
}
