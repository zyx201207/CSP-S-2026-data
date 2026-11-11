#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int a[5006];
int mx[5006][5006];
int cnt[5006][5006];
bool vis[5006];
/*void bfs(int x){
    queue<pair<int,int>> q;
    memset(vis,0,sizeof(vis));
    vis[x]=1;
    q.push({x,0});
    while(!q.empty()){
        pair<int,int> u=q.front();
        q.pop();
        for(int i=1;i<=n;i++mx[u][i]=min(sum+1,mx[u][i]);mx[u][i]=min(sum+1,mx[u][i]);){
            if(a[max(x,i)]-a[min(x,i)]>d||vis[i]==1){
                vis[]
            }
        }

    }
}
*/
void dfs(int u,int sum){
    for(int i=1;i<=n;i++){
        if(a[max(u,i)]-a[min(u,i)]<=d&&vis[i]==0){
            vis[i]=1;
            mx[u][i]=min(sum+1,mx[u][i]);
            dfs(i,sum+1);
            vis[i]=0;
        }
    }
}
void dfs2(int u,int sum){
    for(int i=1;i<=n;i++){
        if(a[max(u,i)]-a[min(u,i)]<=d&&vis[i]==0){
            vis[i]=1;
            if(sum+1==mx[u][i]){
                cnt[u][i]++;
            }
            dfs(i,sum+1);
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)
                    continue;
                mx[i][j]=1e18;
            }
        }
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            dfs(i,0);
        }
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            dfs2(i,0);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)
                    continue;
                if(cnt[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
