#include<bits/stdc++.h>
using namespace std;

int w[505];
int k[505];
int a[505][505];
int t[505][505];
vector<int> g[505];
int c,n,m,d,q;
int ans;
int x,y;
bool vis[505];
void dfs(int cost,int id){
    for(int i=1;i<=k[id];i++){
        if(a[id][i]==y){
            ans=min(ans,cost);
            return;
        }
    }
    for(int i=1;i<=k[id];i++){
        if(g[k[i]].size()!=1){
            for(int j=0;j<=g[k[i]].size()-1;j++){
                if(g[k[i]][j]!=id){
                    if(!vis[g[k[i]][j]]){
                        vis[g[k[i]][j]]=true;
                        dfs(cost+w[g[k[i]][j]]+t[g[k[i]][j]][id],g[k[i]][j]);
                    }
                }

            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d",&a[i][j]);
            g[a[i][j]].push_back(i);
            scanf("%d",&t[i][j]);
            t[j][i]=t[i][j];
        }
    }

    for(int i=1;i<=q;i++){
        memset(vis,0,sizeof(vis));
        scanf("%d",&x);
        scanf("%d",&y);
        ans=1e9;
        dfs(0,x);
        cout<<ans<<endl;
    }

}
