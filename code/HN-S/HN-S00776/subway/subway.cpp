#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int c,n,m,d,q,w[N],sz[N];
vector<int> a[N],t[N];
int dis[505][505];
vector<pair<int,int>> g[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>sz[i];
        for(int j=1;j<=sz[i];j++){
            int x,y;
            cin>>x>>y;
            g[x].push_back({i,y});
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        for(auto x:g[i]){
            for(auto y:g[i]){
                if(x.first==y.first) dis[x.first][y.first]=0;
                // x->y
                else dis[x.first][y.first]=min(dis[x.first][y.first],x.second+y.second);
            }
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        int res=2e18;
        for(auto k1:g[x]){
            for(auto k2:g[y]){
                // cout<<"ID: "<<k1.first<<' '<<k2.first<<"\n";
                // cout<<dis[1][1]<<"\n";
                res=min(res,dis[k1.first][k2.first]+w[x]+w[y]+k1.second+k2.second);
                // if(res==23){
                //     cout<<k1.first<<" "<<k2.first<<"\n";
                //     cout<<w[x]<<" "<<w[y]<<" "<<dis[k1.first][k2.first]<<"\n";
                // }
            }
        }
        cout<<res<<"\n";
    }
}