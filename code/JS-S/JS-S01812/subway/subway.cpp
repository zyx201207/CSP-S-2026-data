#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
    int v,p;
};
vector<edge>e[500501];
//500000 points 500 lines
int v[500001];int d[200501];int pd[501][501];
int vis[500501];
void dij(int px){
    priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > >q;
    q.push({0,px});
    d[px]=0;
    //vis[px]=1;
    while(q.size()){
        int u=q.top().second;
        int p1=q.top().first;
        q.pop();
        //if(vis[u])continue;
        for(int i=0;i<e[u].size();i++){
            int v=e[u][i].v;

            int p=e[u][i].p;
            if(p1+p<d[v]){
                d[v]=p1+p;
                q.push({d[v],v});
               // vis[v]=1;
            }
        }
    }

    for(int i=20001;i<=20500;i++){
        pd[px-20000][i-20000]=d[i];
    }
}


signed main(){
    ios::sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,l,n,da,q;
    cin>>c>>l>>n>>da>>q;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=l;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            e[i+20000].push_back({x,y});
            e[x].push_back({i+20000,y});
        }
    }

    for(int i=1;i<=l;i++){
        for(int j=1;j<=20500;j++){d[j]=0x3f3f3f3f3f;vis[j]=0;}
        //memset(d,0x3f,sizeof d);
      //  memset(vis,0,sizeof vis);
        dij(20000+i);
        //cout<<pd[1][2]<<endl;
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int ans=0x3f3f3f3f3f;
        for(int j=0;j<e[x].size();j++){
            if(e[x][j].v>=20000){
                int k=0x3f3f3f3f3f;
                for(int o=0;o<e[y].size();o++){
                    if(e[y][o].v>=20000)
                    k=min(k,pd[(e[x][j].v)-20000][(e[y][o].v)-20000]+e[y][o].p);
                }
                ans=min(ans,k+e[x][j].p);
            }
        }
        cout<<ans+v[x]+v[y]<<endl;
    }

}
//Chinese are able to fly
