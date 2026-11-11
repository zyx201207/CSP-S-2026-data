#include<bits/stdc++.h>
using namespace std;
#define chennnie return
#define bless 0
#define me ;
int ceshidian,n,m,q,d,maxk=-1;
int w[500005];
struct node{
    int id,t;
};
vector<node>vec[501];
struct edge{
    int v,w;
};
bool operator<(edge a,edge b){return a.w>b.w;}
vector<node>mp[501];
int dis[505];
void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    priority_queue<edge>q;
    dis[s]=0;
    q.push({s,0});
    while(!q.empty()){
        edge u=q.top();q.pop();
        if(u.w!=dis[u.v])continue;
        for(auto &[v,w]:mp[u.v]){
            if(dis[v]>=dis[u.v]+w){
                dis[v]=dis[u.v]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>ceshidian>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        maxk=max(maxk,k);
        for(int j=1;j<=k;j++){
            int lsid,lst;
            cin>>lsid>>lst;
            vec[i].push_back({lsid,lst});

        }
    }
    if(maxk==2){
        for(int i=1;i<=n;i++){
            int u,v,t=0;
            for(int j=0;j<vec[i].size();j++){
                if(j==0)u=vec[i][j].id;
                else v=vec[i][j].id;
                t+=vec[i][j].t;
            }
            mp[u].push_back({v,t});
            mp[v].push_back({u,t});
        }
        while(q--){
            int bg,ed;
            cin>>bg>>ed;
            dij(bg);
            cout<<dis[ed]+w[bg]+w[ed]<<'\n';
        }
    }
}
