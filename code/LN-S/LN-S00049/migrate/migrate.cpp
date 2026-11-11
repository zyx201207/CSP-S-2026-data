#include<bits/stdc++.h>
using namespace std;
int n;
int dp[5010][5010];
long long p[5010][5010];
int rt[5010];

int t,c;
long long a[2000010];
long long d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        if(n<=5000){

        int rf=n;
        for(int i=n;i>=1;i--){
            while(a[rf]-a[i]>d){
                rf--;
            }rt[i]=rf;
        }
        for(int i=1;i<=n;i++){
            dp[i][i]=1;
            p[i][i]=0;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j+i-1<=n;j++){
                dp[j][i+j-1]=0;

                if(rt[j]>=j+i-1){
                    dp[j][j+i-1]=1;
                    p[j][j+i-1]=1;
                }else{

                    for(int k=rt[j];p[rt[j]][j+i-1]==p[k][j+i-1]&&k>j;k--){
                        dp[j][j+i-1]+=dp[k][j+i-1];
                    }
                    p[j][j+i-1]=p[rt[j]][j+i-1]+1;
                    //if(p[j][j+i-1]<=0)p[j][j+i-1]--;
                }
            }

        }int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dp[i][j]==2)ans++;//printf("%d %d\n",i,j);
            }
        }printf("%lld\n",ans);
        }else{
            long long g=a[2]-a[1];
            long long u=d/g+1;
            if(g>d){
                printf("0\n");
            }else
                printf("%d\n",max(0LL,(n-1)-u+1));
        }

    }
    return 0;
}
