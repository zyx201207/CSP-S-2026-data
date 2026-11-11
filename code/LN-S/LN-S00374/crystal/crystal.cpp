#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        if(a[i]-a[i-1]!=a[i+1]-a[i]){
            int l=1,r=i,mid;
            while(l<=r){
                mid=l+r>>1;
                if((a[i]-a[i-1])*(i-mid+1)-(a[i]-a[mid-1])<=m){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            ans=max(ans,i-l+1);
        }
    }
    printf("%lld",ans);
    return 0;
}
