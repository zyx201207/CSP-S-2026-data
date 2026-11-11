#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500100],pre[500100];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=l+r>>1;
            if((i-mid+1)*a[i]-(pre[i]-pre[mid-1])<=m)
                r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    printf("%d\n",ans);
    //Oct31==Dec25?
    return 0;
}