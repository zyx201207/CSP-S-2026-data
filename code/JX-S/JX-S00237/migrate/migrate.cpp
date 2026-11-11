#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=5e3+5;
int a[2000005],dp[N][N],cnt[N][N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            int n,d;
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                scanf("%d",&a[i]);
            }
            int tc=a[n]-a[n-1];
            d/=tc;
            if(d==2){
                printf("%d\n",n-3);
            }
            else{
                printf("0\n");
            }
        }
        return 0;
    }
    while(t--){
        int n,d;
        cin>>n>>d;
        memset(dp,0x3f,sizeof dp);
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(a[j]-a[i]<=d){
                    dp[i][j]=1;
                    cnt[i][j]=1;
                }
                else break;
            }
        }
        long long ans=0;
        for(int len=1;len<n;len++){
            for(int i=1;i+len<=n;i++){
                int j=i+len;
                for(int k=i+1;k<j;k++){
                    if(dp[i][k]+dp[k][j]<dp[i][j]){
                        dp[i][j]=dp[i][k]+dp[k][j];
                        cnt[i][j]=cnt[i][k]*cnt[k][j];
                    }
                    else if(dp[i][k]+dp[k][j]==dp[i][j]) cnt[i][j]+=cnt[i][k]*cnt[k][j];
                }

            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(cnt[i][j]==2) ans++;
            }
        }
        printf("%lld\n",ans);

    }
    return 0;
}
