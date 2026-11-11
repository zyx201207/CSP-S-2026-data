#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=505,M=5e5+5;
const ll inf=1e18;
int c,n,m,d,q;
int k[N];
ll w[M],dis[N][N],wis[N][N];
vector<int> a[N],t[N];
vector<pair<int,int> > in[M];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            wis[i][j]=wis[j][i]=inf,
            dis[i][j]=dis[j][i]=inf;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,x,y;j<=k[i];j++){
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
            in[x].push_back({i,j-1});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<in[i].size();j++) for(int k=j+1;k<in[i].size();k++){
            int x=in[i][j].first,y=in[i][k].first;
            int ix=in[i][j].second,iy=in[i][k].second;
            dis[x][y]=min(dis[x][y],ll(t[x][ix]+t[y][iy]));
            dis[y][x]=min(dis[y][x],ll(t[x][ix]+t[y][iy]));
            wis[x][y]=wis[y][x]=dis[x][y];
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int u,v;
        cin>>u>>v;
        ll ans=inf;
        for(int i=0;i<in[u].size();i++) for(int j=0;j<in[v].size();j++){
            int x=in[u][i].first,y=in[v][j].first;
            int ix=in[u][i].second,iy=in[v][j].second;
            ans=min(ans,ll(t[x][ix]+t[y][iy]+dis[x][y]));
        }
        cout<<ll(ans+w[u]+w[v])<<"\n";
    }
    return 0;
}