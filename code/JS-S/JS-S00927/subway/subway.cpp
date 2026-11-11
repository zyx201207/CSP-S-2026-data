#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500005;
vector<pair<int,int>> line[maxn];
int w[maxn],dis[505][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            line[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            dis[i][j]=1e18;
    }
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int trans=1;trans<=m;trans++){
        for(auto l1:line[trans]){
            for(auto l2:line[trans]){
                if(l1==l2)
                    continue;
                int u=l1.first,v=l2.first;
                dis[u][v]=min(dis[u][v],l1.second+l2.second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    while(q--){
        int x,y,ans=1e18;
        cin>>x>>y;
        for(auto a:line[x]){
            for(auto b:line[y]){
                if(a.first==b.first)
                    ans=min(ans,a.second+b.second);
                else
                    ans=min(ans,dis[a.first][b.first]+a.second+b.second);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
