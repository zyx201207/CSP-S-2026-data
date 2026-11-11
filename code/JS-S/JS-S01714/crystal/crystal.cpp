#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
    for(int i=1;i<=n;i++){
        long long l=1,r=i,pos=0;
        while(l<=r){
            long long mid=l+r>>1,sum=b[i]-b[mid-1],len=i-mid+1;
            if(a[i]*len-sum<=m) pos=mid,r=mid-1;
            else l=mid+1;
        }
        if(pos<=0||pos>i) continue;
        ans=max(ans,i-pos+1);
    }
    printf("%lld\n",ans);
    return 0;
}