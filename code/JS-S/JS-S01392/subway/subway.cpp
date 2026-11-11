#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXM=5e5+10,MAXN=510,inf=1e18;
ll c,n,m,d,q,w[MAXM],k[MAXN],S;
bool vis[MAXM];
vector<ll> a[MAXN],t[MAXN];
vector<pair<ll,ll> > E[MAXM];
ll dis[MAXM],idx;
ll ID[210][410];
ll id(ll x,ll y){return ID[x][y]!=0?ID[x][y]:ID[x][y]=++idx;}
void add(ll x,ll y,ll z){E[x].push_back(make_pair(y,z));}
ll dijkstra(ll x,ll y){
    for(ll i=0;i<=idx;i++) dis[i]=inf,vis[i]=0;
    priority_queue<pair<ll,ll> > Q;while(!Q.empty()) Q.pop();
    dis[x]=0;Q.push(make_pair(0,x));
    while(!Q.empty()){
        ll d=-Q.top().first,u=Q.top().second;Q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(ll i=0;i<E[u].size();i++){
            ll v=E[u][i].first,w=E[u][i].second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;Q.push(make_pair(-dis[v],v));
            }
        }
    }
    return dis[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++) cin>>w[i];
    for(ll i=1;i<=n;i++){
        cin>>k[i];a[i].resize(k[i]+7);t[i].resize(k[i]+7);S+=k[i];
        for(ll j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
    }   
    if(c<=8||(12<=c&&c<=15)){
        for(ll i=1;i<=n;i++){
            add(id(i,a[i][1]),id(n+1,a[i][1]),t[i][1]);
            add(id(n+1,a[i][1]),id(i,a[i][1]),t[i][1]);
            for(ll j=2;j<=k[i];j++){
                add(id(i,a[i][j-1]),id(i,a[i][j]),0);
                add(id(i,a[i][j]),id(i,a[i][j-1]),0);
                add(id(i,a[i][j]),id(n+1,a[i][j]),t[i][j]);
                add(id(n+1,a[i][j]),id(i,a[i][j]),t[i][j]);
            }
        }
        // for(ll i=1;i<=n+1;i++){
        //     for(int j=1;j<=m;j++) cout<<ID[i][j]<<" ";
        //     cout<<"\n";
        // }
        // for(ll i=1;i<=idx;i++){cout<<i<<"    ";
        //     for(ll j=0;j<E[i].size();j++) cout<<E[i][j].first<<" "<<E[i][j].second<<"    ";
        //     cout<<"\n";
        // }
        while(q--){
            ll x,y,ans=inf;cin>>x>>y;
            ans=dijkstra(id(n+1,x),id(n+1,y));
            cout<<w[x]+ans+w[y]<<"\n";
        }
        return 0;
    }
    return 0;
}