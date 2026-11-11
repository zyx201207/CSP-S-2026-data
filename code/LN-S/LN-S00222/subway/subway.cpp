#include<bits/stdc++.h>
using namespace std;
const int N=23170;
int c,n,m;
int d,q;
int dp[N][N];
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
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=2*m+n;i++){
        for(int j=1;j<=2*m+n;j++){
            dp[i][j]=0x3f3f3f3f;
        }
        dp[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int w;
        cin>>w;
        dp[i][i+m]=w;
        dp[i+m][i]=w;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u,t;
            cin>>u>>t;
            dp[u+m][2*m+i]=t;
            dp[2*m+i][u+m]=t;
        }
    }
    floyd(2*m+n);
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        cout<<dp[u][v]<<"\n";
    }
    return 0;
}
