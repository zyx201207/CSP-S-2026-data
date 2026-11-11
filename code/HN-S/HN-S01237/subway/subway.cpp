#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=5e5+7;
const int maxn=507;
const int inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[maxm],k[maxn];
int dis[maxn][maxn];
struct edge{
    int v,w;
    edge(int v=0,int w=0): v(v),w(w){}
};
vector<edge>e[maxm];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=inf;
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a,t;
            cin>>a>>t;
            for(edge l:e[a]){
                dis[i][l.v]=min(dis[i][l.v],t+l.w);
                dis[l.v][i]=min(dis[l.v][i],t+l.w);
            }
            e[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int l=1;l<=n;l++){
                dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int ans=inf;
        for(edge j:e[x]){
            for(edge l:e[y]){
                ans=min(ans,j.w+l.w+dis[j.v][l.v]);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}
