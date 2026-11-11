#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long m,a[500050],mm,pre[500050],erp[500050];
int ef(int i){
    int l=1,r=i,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(mid*a[i]-erp[i-mid+1]<=m)l=mid;
        else r=mid+1;
    }
    return mid;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);

    }
    sort(a+1,a+n+1);
    mm=m;
    if(n<=5000){
        for(int i=1;i<=n;++i){
            m=mm;
            int j=1,res=0;
            while(m>=0&&j<=n){
                if(a[j]>a[i])break;
                else if(m-a[i]+a[j]>=0){
                    m-=(a[i]-a[j]);
                    ++res;
                }
                ++j;
            }
            ans=max((long long)res,ans);
        }
        printf("%lld",ans);
    }
    else{
        for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
        for(int i=1;i<=n;++i){
            if(a[i]*i-pre[i]<=m){
                ans=i;
            }
            printf("%lld",ans);
        }
        printf("%lld",ans);
    }
    return 0;
}
