#include<bits/stdc++.h>
using namespace std;
const int MAXN=5010;
long long c,t,n,d,x[MAXN],son[MAXN],dp[MAXN][MAXN],ans,dis[MAXN][MAXN],fa[MAXN];
/*
void dfs(int st,int x,int step){
    if(step<dis[st][x]) dp[st][x]=1,dis[st][x]=step;
    dp[st][x]++;
    for(int i=x+1;i<=x+son[x];i++){
         if(dp[st][i]<=2) dfs(st,i,step+1);
    }
    return ;
}
*/
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){

        cin>>n>>d;
        ans=0;
        memset(dp,0,sizeof(dp));
        memset(x,0,sizeof(x));
        memset(son,0,sizeof(son));
        memset(fa,0,sizeof(fa));
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++) dis[i][j]=1e9+10;
        }
        x[0]=-2147483647;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            dis[i][i]=0;
            for(int j=i-1 ; j>=1&&x[i]-x[j]<=d ;j--){
                son[j]++,fa[i]++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j-fa[j];k<j;k++){
                    if(k<i) continue;
                    if(dis[i][j]==dis[i][k]+1) dp[i][j]++;
                    if(dis[i][j]>dis[i][k]+1){
                        dis[i][j]=dis[i][k]+1;
                        dp[i][j]=1;
                    }
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dp[i][j]==2) ans++;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
