#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
int n;
ll m;
ll a[500005],sa[500005];
inline bool cmp1(int a,int b){
    return a<b;
}
inline bool check(int mid,int r){
    return (r-mid+1)*a[r]-(sa[r]-sa[mid-1])<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,cmp1);
    for(int i=1;i<=n;i++){
        sa[i]=sa[i-1]+a[i];
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        int l=1;
        int r=i;
        int efans=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid,i)){
                r=mid-1;
                efans=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-efans+1);
    }
    printf("%d",ans);
    return 0;
}
//jxsj