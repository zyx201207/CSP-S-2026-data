#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],yyr[2000005],zz[2000005],yqh[2000005],ans;
long long solve1(long long a){
    long long l=a,r=n,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(x[mid]>x[a]+d)
            r=mid-1;
        else
            l=mid+1;
    }
    return r;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        memset(zz,0,sizeof(zz));
        memset(yqh,0,sizeof(yqh));
        ans=0;
        scanf("%lld%lld",&n,&d);
        for(long long i=1;i<=n;++i)
            scanf("%lld",&x[i]);
         for(long long i=1;i<=n;++i){
            yyr[i]=solve1(i);
        }
        for(long long i=2;i<=n;++i){
            if(yyr[i-1]==i&&yyr[i-2]!=i){
                zz[i]=zz[i-1]+1;
            }
            else{
                zz[i]=0;
            }
        }
        for(long long i=n-1;i>=1;--i){
            if(yyr[i]==i+1&&yyr[i-1]!=i+1){
                yqh[i]=yqh[i+1]+1;
            }
            else{
                yqh[i]=0;
            }
        }
        for(long long i=1;i<=n;++i)
            if(yyr[i]!=i&&yyr[i]!=i+1){
                if(yyr[yyr[i]-1]>yyr[yyr[i]-2]){
                    ans+=(zz[i]+1)*(yqh[yyr[yyr[i]-1]]+(yyr[yyr[i]-1]-yyr[yyr[i]-2]));
                }
            }
        printf("%lld\n",ans);
    }
    return 0;
}
