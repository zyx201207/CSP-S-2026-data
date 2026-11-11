#include <bits/stdc++.h>
using namespace std;
const int N=606,M=6e5+5;
long long dis[N][N],w[M];
bool f[N];
vector<pair<int,long long> >sta[M];
vector<pair<int,long long> >edg[N];

void dij(int x){
    memset(dis[x],-1,sizeof(dis[x]));
    memset(f,0,sizeof(f));
    priority_queue<pair<long long,int> >pq;
    pq.push({0,x});
    dis[x][x]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        long long w=pq.top().first;
        pq.pop();
        w=-w;
        f[u]=1;
        for(int i=0;i<edg[u].size();i++){
            int v=edg[u][i].first;
            long long w=edg[u][i].second;
            if(!f[v]&&(dis[x][v]>dis[x][u]+w||dis[x][v]==-1)){
                dis[x][v]=dis[x][u]+w;
                pq.push({-dis[x][v],v});
            }
        }
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=0,a;j<k;j++){
            long long t;
            cin>>a>>t;
            sta[a].push_back({i,t});
        }
    }
    //cerr<<'c';
    for(int i=1;i<=m;i++)
        for(int j=0;j<sta[i].size();j++)
            for(int k=j+1;k<sta[i].size();k++){
                int u=sta[i][j].first;
                long long w=sta[i][j].second;
                int v=sta[i][k].first;
                long long g=sta[i][k].second;
                edg[u].push_back({v,w+g}),edg[v].push_back({u,w+g});
            }

    //cerr<<'a';
    for(int i=1;i<=n;i++)dij(i);
    //cerr<<'b';
    while(q--){
        int u,v;
        long long res=-1;
        cin>>u>>v;
        for(int i=0;i<sta[u].size();i++)
            for(int j=0;j<sta[v].size();j++){
                int a=sta[u][i].first;
                long long s=sta[u][i].second;
                int b=sta[v][j].first;
                long long g=sta[v][j].second;
                if(res==-1||res>dis[a][b]+s+g+w[u]+w[v])
                    res=dis[a][b]+s+g+w[u]+w[v];
            }
        cout<<res<<'\n';
    }
    return 0;
}
