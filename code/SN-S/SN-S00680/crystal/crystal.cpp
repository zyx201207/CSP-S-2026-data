#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005],ans;
bool smaller_than_k[500005];
int absl(int x){
    return (x>=0 ? x : -x);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    smaller_than_k[0]=1;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        smaller_than_k[i]=((a[i]<=m)&&(smaller_than_k[i-1]));
        if(absl(s[i]-(a[i]*i))<=m&&smaller_than_k[i]){
            ans=max(ans,i);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
