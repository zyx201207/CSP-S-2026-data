#include<bits/stdc++.h>
using namespace std;

int main (){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    for(int g=1;g<=t;g++){
        int ans=0;
        int n,d;
        scanf("%d%d",&n,&d);
        long long dp[n+1][n+1];
        int way[n+1][n+1];
        memset(way,0,sizeof(way));
        for(int i=0;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=INT_MAX;
        int x[n+1];
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
            dp[i][i-1]=1;
            dp[i-1][i]=1;
            dp[i][i]=0;
            way[i][i-1]=1;
            way[i-1][i]=1;
            for(int j=i-2;j>=1;j--)
                if(x[i]-x[j]<=d){
                    dp[i][j]=1;
                    dp[j][i]=1;
                    way[i][j]=1;
                    way[i][j]=1;
                }else
                    break;
        }

        for(int k=1;k<=n;k++)
            for(int u=1;u<=n-2;u++){
                if(k==u) continue;
            //vector<int> temp;
            //for(int p=u+1;p<=n-3;p++)
            //    if(dp[u][p]==1) temp.push_back(p);
                for(int v=u+2;v<=n;v++){
                    if(k==v) continue;
                    if(dp[u][v]!=dp[u][k]+dp[k][v]){
                        if(dp[u][v]>dp[u][k]+dp[k][v]){
                            way[v][u]=1;
                            way[u][v]=1;
                        }
                        dp[u][v]=min(dp[u][v],dp[u][k]+dp[k][v]);
                        dp[v][u]=dp[u][v];
                    }else{
                        way[v][u]++;
                        way[u][v]++;
                    }
                //if(dp[u][v]==1) continue;
                //int sum=0;
                //for(int i=0;i<temp.size();i++)
                //    if(dp[temp[i]][v]==1) sum++;
                //if(sum==2) ans++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(way[i][j]==2) ans++;
                //cout<<way[i][j]<<" ";
            }
            //cout<<endl;
        }
        cout<<ans/2<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
