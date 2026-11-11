#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N=5e5+10;
int w[N];
const int M=500+10;
int a[M][M],t[M][M];
int dp[M][M];
int k[M];
int ans=0;
vector<pair<int,int>>g[N];
signed main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>t[i][j];
            dp[a[i][j-1]][a[i][j]]=t[i][j];
            dp[a[i-1][j]][a[i][j]]=t[i-1][j]+t[i][j];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j]){
                    continue;
                }else {
                    dp[i][j]=INT_MIN;
                }
                if(i==j){
                    dp[i][j]=0;
                }

            }
        }
        for(int jump=1;jump<=n;jump++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dp[i][j]=max(dp[i][j],dp[i][jump]+dp[jump][j]);
                }
            }
        }
        cout<<dp[x][y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
