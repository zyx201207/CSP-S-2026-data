#include "bits/stdc++.h"
using namespace std;
int c,t,n;
long long d;
long long x[2000010];
long long dit[2000010];//i~i+1
long long m;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int times=1;times<=t;times++){
        scanf("%d%lld",&n,&d);
        long long ans=0;
        const int N=n+10;
        int dp[N][N];
        int cot[N][N];
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
            dit[i-1]=x[i]-x[i-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j+i<=n;j+=i){
                cot[i][j+i]=1E10;
                dp[i][j]=0;
                if(x[j+i]-x[i]<=d){
                    dp[i][i+j]=1;
                    cot[i][i+j]=1;
                }
                else{
                    for(int t=i+1;t<i+j;t++){
                        if(cot[i][i+j]>cot[i][t]+cot[t][j]){
                            dp[i][i+j]=dp[i][]
                        }
                    }
                }
                if(dp[i][i+j]==2) ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
