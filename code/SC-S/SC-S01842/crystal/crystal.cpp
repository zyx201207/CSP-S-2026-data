#include<cstdio>
#include<algorithm>
#define N 500005
int n,ans;
long long m,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        while(l<=r){
            mid=l+r>>1;
            if((i-mid+1)*a[i]-s[i]+s[mid-1]<=m)ans=std::max(ans,i-mid+1),r=mid-1;
            else l=mid+1;
        }
    }
    printf("%d",ans);
}