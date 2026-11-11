#include<bits/stdc++.h>
using namespace std;
struct node{
    int v;
    long long w;
};
vector<node>G[600005];
int c,n,m,d,q;
int idx;
long long dis[600005];
long long Dis[505][505];
bool vdis[505];
bool vis[600005];
void dijkstra(int st,int ed){
    vdis[st]=true;
    priority_queue<pair<long long,int> >q;
    for(int i=1;i<=idx;i++){
        vis[i]=false;
        dis[i]=10000000000000000;
    }
    dis[st]=0;
    q.push(make_pair(0,st));
    while(q.size()){
        int now=q.top().second;q.pop();
        if(vis[now])continue;
        vis[now]=true;
       // cout<<now<<endl;
        for(int i=0;i<G[now].size();i++){
            if(dis[G[now][i].v]>dis[now]+G[now][i].w){
                dis[G[now][i].v]=dis[now]+G[now][i].w;
                q.push(make_pair(-dis[G[now][i].v],G[now][i].v));
            }
        }
    }
    for(int i=1;i<=n;i++){
        Dis[st][i]=dis[i];
       // cout<<dis[i]<<' ';
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    idx=n;
    for(int i=1;i<=n;i++){
        long long w;
        cin>>w;
        G[i].push_back({i+idx,w});
        G[i+idx].push_back({i,w});
    }
    idx=idx+n;
    for(int i=1;i<=m;i++){
        int k;
        int a;
        long long t;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            G[a+n].push_back({j+idx,t});
            G[j+idx].push_back({a+n,t});
            if(j!=1){
                G[j+idx-1].push_back({j+idx,0});
                G[j+idx].push_back({j+idx-1,0});
            }
        }
        idx=idx+k;
    }
  /*  for(int i=1;i<=idx;i++){
        for(int j=0;j<G[i].size();j++){
                cout<<i<<' '<<G[i][j].v<<' '<<G[i][j].w<<endl;
            }
        }*/
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(vdis[x]==false){
            dijkstra(x,y);
        }
        printf("%lld\n",Dis[x][y]);
    }
    return 0;
}
