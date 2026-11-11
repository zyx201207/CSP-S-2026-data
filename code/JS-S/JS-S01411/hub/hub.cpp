#include"bits/stdc++.h"
using namespace std;
int c,n,m,d,q;
int w[500100];
int walk[500100][21],cnt[500100];
vector<pair<int,int> >g[500100];
vector<pair<int,int> >mst[500100];
int f[500100][31];
int dist[500100],dep[500100];
void Kruskal(){
    priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >qu;
    qu.push(make_pair(0,make_pair(0,1)));
    bool in[500100]={0};
    while(!qu.empty()){
        int x=qu.top().second.second,fa=qu.top().second.first;
        int dis=qu.top().first;
        qu.pop();
        if(in[x]) continue;
        mst[fa].push_back(make_pair(x,dis));
        in[x]=1;
        f[x][0]=fa;
        dist[x]=dist[fa]+dis;dep[x]=dep[fa]+1;
        for(pair<int,int>i:g[x]){
            if(in[i.first]) continue;
            qu.push(make_pair(i.second,make_pair(x,i.first)));
        }
    }
}
void init_LCA(){
    queue<int>d;
    d.push(1);
    while(!d.empty()){
        int tem=d.front();
        d.pop();
        for(int i=1;i<=30;i++){
            f[tem][i]=f[f[tem][i-1]][i-1];
            if(f[tem][i]==0) break;
        }
        for(pair<int,int>i:mst[tem]) d.push(i.first);
    }
}
int LCA(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    int jump=dep[x]-dep[y];
    if(jump){
        for(int i=0;i<=30;i++){
            if((jump>>i)&1) x=f[x][i];
            if(dep[x]==dep[y]) break;
        }
    }
    if(x==y) return x;
    for(int i=30;i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i],y=f[y][i];
        }
    }
    return f[x][0];
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.ans","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        vector<int>x1;x1.push_back(0);
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            x1.push_back(x);
            walk[x][++cnt[x]]=y;
        }
        for(int j=1;j<=k;j++){
            for(int j2=j+1;j2<=k;j2++){
                g[x1[j]].push_back(make_pair(x1[j2],walk[x1[j]][cnt[x1[j]]]+walk[x1[j2]][cnt[x1[j2]]]));
                g[x1[j2]].push_back(make_pair(x1[j],walk[x1[j]][cnt[x1[j]]]+walk[x1[j2]][cnt[x1[j2]]]));
            }
        }
    }
    Kruskal();
    /*for(int i=1;i<=m;i++){
        cout<<"mst i:";
        for(pair<int,int> j:mst[i]) cout<<j.first<<' '<<j.second<<' ';
        cout<<endl;
    }
    for(int i=1;i<=m;i++) cout<<f[i]<<' ';*/
    init_LCA();
    /*for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            cout<<i<<' '<<j<<' '<<LCA(i,j)<<endl;
        }
    }*/
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<dist[u]+dist[v]-2*dist[LCA(u,v)]+w[u]+w[v]<<'\n';
    }
}
