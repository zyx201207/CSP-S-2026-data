#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[500007],pre[500007];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    int l=1,r=1,len=1,sum=0;
    while(r<n){
        while(l<=r&&sum>m)sum-=(a[r]-a[l]),l++,len--;
        //printf("%lld %lld %d %lld %lld %lld\n",sum,len,(sum>m),ans,l,r);
        ans=max(ans,len);
        sum+=(a[r+1]-a[r])*len;
        len++;
        r++;
    }
    printf("%lld",ans);
    return 0;
}
/*
1 2 4 8 9
1248->17(+(8-1))
248->10
2489->13
*/
/*
wo ren wei shi yi ge bei bao?
cuo wu de
*/
/*
for(int i=1;i<n;i++)pre[i]=pre[i-1]+a[n]-a[i];
    int l=1,r=1,len=0;
    while(r<=n){
        while(l<=r&&pre[r]-pre[l]>=m)l++,len--;
        len++;
        ans=max(ans,len);
        r++;
    }
    cout<<ans;
*/
