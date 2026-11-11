#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long LL;
struct Node{
    int ms,co;
}dp[N];
int c,t;
LL a[N];
int n;
LL d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        LL ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)dp[j].co=0,dp[j].ms=0;
            dp[i].ms=1,dp[i].co=1;
            for(int k=i+1;k<=n;k++){
                int cnt=0,minx=0x3f3f3f3f;
                for(int j=i;j<k;j++){
                    if(a[k]-a[j]<=d){
                        if(cnt==0&&minx==0x3f3f3f3f){
                            minx=dp[j].ms;
                            cnt=1;
                        }
                        else{
                            if(dp[j].ms==minx)cnt++;
                        }
                    }
                }
                dp[k].co=cnt,dp[k].ms=minx+1;
            }
            for(int j=1;j<=n;j++){
                if(dp[j].co==2)ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
