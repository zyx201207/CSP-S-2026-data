#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k,a,t,dp[605][605],x,y,ans;
struct node{
    long long v1,w1;
};
vector<node>b[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c<=8){
        for(int i=1;i<=n+m;i++){
            for(int j=1;j<=n+m;j++){
                if(i==j)dp[i][j]=0;
                else dp[i][j]=1e16;
            }
        }
        for(int i=1;i<=m;i++)
        cin>>w[i];
        for(int i=1;i<=n;i++){
            cin>>k;
            while(k--){
                cin>>a>>t;
                dp[i+m][a]=dp[a][i+m]=t;
            }
        }
        for(int k=1;k<=n+m;k++)
        for(int i=1;i<=n+m;i++)
        for(int j=1;j<=n+m;j++)
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        while(q--){
            cin>>x>>y;
            cout<<w[x]+w[y]+dp[x][y]<<'\n';
        }
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)dp[i][j]=0;
                else dp[i][j]=1e16;
            }
        }
        for(int i=1;i<=m;i++)
        cin>>w[i];
        for(int i=1;i<=n;i++){
            cin>>k;
            while(k--){
                cin>>a>>t;
                b[a].push_back({i,t});
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=0;j<b[i].size();j++){
                for(int k=j+1;k<b[i].size();k++){
                    dp[b[i][j].v1][b[i][k].v1]=dp[b[i][k].v1][b[i][j].v1]=min(dp[b[i][j].v1][b[i][k].v1],b[i][j].w1+b[i][k].w1);
                }
            }
        }
        for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        while(q--){
            ans=1e16;
            cin>>x>>y;
            for(int i=0;i<b[x].size();i++)
            for(int j=0;j<b[y].size();j++)
            ans=min(ans,dp[b[x][i].v1][b[y][j].v1]+b[x][i].w1+b[y][j].w1);
            cout<<w[x]+w[y]+ans<<'\n';
        }
    }
    return 0;
}

