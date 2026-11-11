#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1.414e4+5,INF=1e9+5;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        int n,d,ans=0,x[N],dp[N][N];
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            dp[i][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j-1;k>=1 && x[j]-x[k]<=d;j--){
                    dp[i][j]+=dp[i][k];
                }
                if(dp[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans;
    }

    return 0;
}