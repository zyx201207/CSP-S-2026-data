#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500010],k[510];
struct aaaa{
    int w,t;
};
vector<aaaa>v[500010];
int dis[510][510];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int x=1;x<=m;x++){
        cin>>w[x];
    }
    for(int x=1;x<=n;x++){
        cin>>k[x];
        for(int y=1;y<=k[x];y++){
            int a,b;
            cin>>a>>b;
            v[a].push_back({x,b});
        }
    }
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            dis[x][y]=1e17;
        }
    }
    for(int x=1;x<=n;x++)dis[x][x]=0;
    for(int x=1;x<=m;x++){
        for(auto y:v[x]){
            for(auto z:v[x]){
                if(y.w==z.w)continue;
                dis[y.w][z.w]=min(dis[y.w][z.w],y.t+z.t);
            }
        }
    }
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            for(int z=1;z<=n;z++){
                dis[y][z]=min(dis[y][z],dis[y][x]+dis[x][z]);
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        int ans=1e17;
        for(auto y:v[a]){
            for(auto z:v[b]){
                ans=min(ans,dis[y.w][z.w]+y.t+z.t);
            }
        }
        cout<<ans+w[a]+w[b]<<'\n';
    }
}