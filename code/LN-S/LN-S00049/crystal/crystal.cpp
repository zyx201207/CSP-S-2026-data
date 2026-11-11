#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
int n;
long long m;
long long a[500010];
long long sum[500010];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }int ans=1;
    for(int i=1;i<=n;i++){
        int l=0,r=i;
        while(l+1<r){
            int mm=(l+r)/2;
            if(a[i]*(i-mm+1)-(sum[i]-sum[mm-1])<=m)r=mm;
            else l=mm;
        }ans=max(ans,i-l);
    }printf("%d\n",ans);
    return 0;
}
