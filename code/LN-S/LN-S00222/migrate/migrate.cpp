#include<bits/stdc++.h>
using namespace std;
const int N=23169;
int c,t,b[N],dp[N][N];
void floyd(int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=0x3f3f3f3f;
            }
            dp[i][i]=0;
            dp[i][i+1]=1;
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        for(int i=1;i<=n;i++){
            int l=*(upper_bound(b+i,b+n+1,b[i]+d)-1);
            int r;
            for(int j=i;j<=n;j++){
                if(b[j]==l){
                    r=j;
                    break;
                }
            }
            dp[i][r]=1;
        }
        floyd(n);
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dp[i][j]!=0x3f3f3f3f&&dp[i][j]>1){
                    if((j-i)%d&&(j-i)>d){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
