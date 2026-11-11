#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;
#define ll long long
#define endl '\n'
#define inf 0x3f3f3f3f

int g[20005][20005];
int c,n,m,d,q;
int b,e;
int w[(int)5e5+5];
int minn=inf;
bool visited[20005];
void dfs(int node,int tm){
    if(node==e){
        minn=min(minn,w[b]+w[e]+tm);
        return;
    }
    for(int i=1;i<=m;i++){
        if(g[node][i]==inf || visited[i])continue;
        visited[i]=1;
        dfs(i,tm+g[node][i]);
        visited[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)g[i][j]=inf;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        int a,t;
        cin>>a>>t;
        for(int i=2;i<=k;i++){
            int pa,pt;
            pa=a,pt=t;
            cin>>a>>t;
            g[pa][a]=min(g[pa][a],pt+t);
            g[a][pa]=min(g[a][pa],pt+t);
        }
    }
    cin>>q>>b>>e;
    for(int i=0;i<q;i++){
        for(int i=1;i<=m;i++)visited[i]=0;
        dfs(b,0);
        cout<<minn;
    }
    return 0;
}
