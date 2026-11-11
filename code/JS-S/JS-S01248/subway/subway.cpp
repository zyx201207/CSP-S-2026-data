#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 500005
ll c,n,m,d,q2,k,a,b;
ll w[N],dis[1005][1005];
vector<ll>f,g;
vector<pair<ll,ll>>e[N];
bool vis[N];
void planB(){
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q2;
    for(ll i=1;i<=m;i++)
        cin>>w[i];
    for(ll T=1;T<=n;T++){
        cin>>k;
        g.clear();
        f.clear();
        for(ll i=1;i<=k;i++){
            cin>>a;
            g.push_back(a);
            cin>>b;
            f.push_back(b);
        }
        for(ll i=0;i<k;i++)
            for(ll j=0;j<k;j++)
                if(i!=j)
                    e[g[i]].push_back({g[j],f[i]+f[j]});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=m;j++)
            dis[i][j]=1e18,vis[j]=0;
        dis[i][i]=0;
        q.push({0,i});
        while(q.size()){
            ll u=q.top().second,d=q.top().first;
            q.pop();
            if(d!=dis[i][u])
                continue;
            if(vis[u])
                continue;
            vis[u]=1;
            for(auto j:e[u]){
                ll v=j.first,w=j.second;
                if(dis[i][v]>dis[i][u]+w){
                    dis[i][v]=dis[i][u]+w;
                    q.push({dis[i][v],v});
                }
            }
        }
    }
    for(ll i=1;i<=q2;i++){
        ll x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
