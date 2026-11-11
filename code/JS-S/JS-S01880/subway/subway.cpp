#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
queue<int>qu;
int w[maxn];
int dis[maxn];
struct edg{
    int v,va;
};
vector<edg>g[maxn];

int vis[maxn];
void dij()
{
    while(!qu.empty()){
        int t=qu.front();
        qu.pop();
        for(int i=0;i<g[t].size();i++){
            edg son=g[t][i];
            if(vis[son.v])continue;
            if(dis[son.v]>son.va+dis[t]){
                vis[son.v]=1;
                dis[son.v]=son.va+dis[t];
                qu.push(son.v);
            }
        }
    }
    return ;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int n,m,c,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if(c<=30){
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            for(int j=1;j<=k;j++){
                int a,t;
                cin>>a>>t;
                edg tp;
                tp.v=a+n;
                tp.va=t;
                g[j].push_back(tp);
                tp.v=j;
                g[a+n].push_back(tp);
            }
        }
        for(int i=1;i<=q;i++){
            memset(vis,0,sizeof(vis));
            memset(dis,0x3f3f3f3f,sizeof(dis));
            int x,y;
            cin>>x>>y;
            dis[x]=0;
            qu.push(x);
            dij();
            int ans=dis[y];
            ans+=w[x]+w[y];
            cout<<ans<<endl;
        }
    }
    return 0;
}
