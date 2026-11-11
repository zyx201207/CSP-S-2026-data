#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq,w[500005],k[500005],a,t,x,y,dp[5005][5005],vis[5005][5005],ans;
struct node{
    int id,tim;
};
node v[5005][5005];
bool f[500005];
vector<node>vv[500005];
priority_queue<node>q;
bool operator<(node aa,node bb){
    return aa.tim>bb.tim;
}
void bfs(int s,int e){
    while(!q.empty())q.pop();
    memset(f,0,sizeof(f));
    q.push({s,0});
    while(!q.empty()){
        int x=q.top().id,y=q.top().tim;q.pop();
        if(f[x])continue;
        f[x]=1;
        if(x==e){
            ans=y;
            return;
        }

        for(int i=0;i<vv[x].size();i++){
            q.push({vv[x][i].id,y+vis[vv[x][i].tim][x]+vis[vv[x][i].tim][vv[x][i].id]});
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            vis[i][a]=t;
            v[i][j]={a,t};
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            for(int l=j+1;l<=k[i];l++){
                vv[v[i][j].id].push_back({v[i][l].id,i});
                vv[v[i][l].id].push_back({v[i][j].id,i});
            }
        }
    }
    for(int i=1;i<=qq;i++){
        cin>>x>>y;ans=0;
        bfs(x,y);
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
