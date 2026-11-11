#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
int c,n,m,d,q;
int w[500005];
int k[1005];
int a[1005][1005];
int t[1005][1005];
int dis[1005][1005];
int bel[500005];
int idx[500005];
struct node{
    int u,v,w;
}tr[505];
int fa[10005];
bool cmp(node x,node y){
    return x.w<y.w;

}
int find(int x){
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
int vis[1005];
vector<pair<int,int>> g[1005];
int di[1005][1005];

void bfs(int x){
    memset(vis,0,sizeof vis);
    queue<pi> qu;
    qu.push({x,0});
    di[x][x]=0;
    vis[x]=1;
    while(!qu.empty()){
        int u=qu.front().first;
        int ll=qu.front().second;
        qu.pop();
        for(auto y: g[u]){
            int v=y.first;
        int w=y.second;
            if(!vis[v]){
                vis[v]=1;
                di[x][v]=w+ll;
                di[v][x]=di[x][v];
                qu.push({v,di[x][v]});
            }
        }
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    if(c<=11&&c>=9){
        for(int i=1;i<=m;i++){
            fa[i]=i;
        }

        for(int i=1;i<=n;i++){
            tr[i]={a[i][1],a[i][2],t[i][1]+t[i][2]};
        }
        sort(tr+1,tr+1+n,cmp);
        for(int i=1;i<=n;i++){
            int fi=find(tr[i].u);
            int fj=find(tr[i].v);
            if(fi!=fj){
                g[tr[i].u].push_back({tr[i].v,tr[i].w});
                g[tr[i].v].push_back({tr[i].u,tr[i].w});
                fa[fi]=fj;
            }

        }
        for(int i=1;i<=m;i++){
            bfs(i);
        }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]+di[x][y]<<endl;
        }
        return 0;
    }

    if(c<=21&&c>=20){
        int mi=1e18;
         for(int i=1;i<=m;i++){
            fa[i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(bel[a[i][j]]){
                    mi=min(t[i][j]+t[1][j],mi);
                }
                bel[a[i][j]]=i;
                idx[a[i][j]]=j;
            }
        }

        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            if(bel[x]==bel[y]){
                cout<<w[x]+w[y]+t[bel[x]][idx[x]]+t[bel[x]][idx[x]]<<endl;
            }
            else{
                cout<<w[x]+w[y]+t[bel[x]][idx[x]]+t[bel[x]][idx[x]]+mi<<endl;
            }
            return 0;

        }
    }
    memset(dis,0x3f,sizeof dis);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            for(int o=1;o<=k[i];o++){
                //e[j].push_back({a[i][o],t[i][j]+t[i][o]});
                //e[o].push_back({a[i][j],t[i][j]+t[i][o]});
                dis[a[i][o]][a[i][j]]=t[i][j]+t[i][o];
                dis[a[i][j]][a[i][o]]=t[i][j]+t[i][o];

            }
        }
    }
    for(int i=1;i<=m;i++){
        dis[i][i]=0;
    }

    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+dis[x][y]<<endl;
    }

    return 0;
}

