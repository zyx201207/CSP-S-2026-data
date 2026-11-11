#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;
const int N=5e5+2;
vector<PII> g[N];
ll dis[502][502];
int a[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            g[x].push_back({i,y});
        }
        for(int j=1;j<=n;j++){
            if(i!=j) dis[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++){
        int sz=g[i].size();
        for(int j=0;j<sz;j++){
            for(int k=0;k<j;k++){
                int u=g[i][j].first,v=g[i][k].first;
                int w=g[i][j].second+g[i][k].second;
                dis[u][v]=min(dis[u][v],(ll)w);
                dis[v][u]=min(dis[v][u],(ll)w);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=1e18;
        for(auto p1:g[x]){
            for(auto p2:g[y]){
                int u=p1.first,v=p2.first;
                int w=p1.second+p2.second;
                ans=min(ans,dis[u][v]+w);
            }
        }
        cout<<ans+a[x]+a[y]<<'\n';
    }
    return 0;
}