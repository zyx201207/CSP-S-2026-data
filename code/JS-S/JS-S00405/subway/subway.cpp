#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll w[500505];
ll k[505];
vector<pair<ll,ll> >g[500505];
ll dis[500505];
ll dis1[1505][1505];
ll n,m;
void dij1(ll start){
    for(ll i=1;i<=n+m;i++)dis1[start][i]=1e9;
    dis1[start][start]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;
    q.push({0,start});
    while(q.size()){
        ll now=q.top().second;
        q.pop();
        for(pair<ll,ll>it:g[now]){
            if(dis1[start][it.first]<=dis1[start][now]+it.second)continue;
            dis1[start][it.first]=dis1[start][now]+it.second;
            q.push({dis1[start][it.first],it.first});
        }
    }
}
void dij(ll start){
    for(ll i=1;i<=n+m;i++)dis[i]=1e9;
    dis[start]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;
    q.push({0,start});
    while(q.size()){
        ll now=q.top().second;
        q.pop();
        for(pair<ll,ll>it:g[now]){
            if(dis[it.first]<=dis[now]+it.second)continue;
            dis[it.first]=dis[now]+it.second;
            q.push({dis[it.first],it.first});
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,d,q;
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1,xx,yy;i<=n;i++){
        cin>>k[i];
        for(ll j=1;j<=k[i];j++){
            cin>>xx>>yy;
            g[xx].push_back({i+m,yy});
            g[i+m].push_back({xx,yy});
        }
    }
    if(c>=9&&c<=11){
        for(ll i=1;i<=m;i++){
            dij1(i);
        }
        ll x,y;
        while(q--){
            cin>>x>>y;
            cout<<dis1[x][y]+w[x]+w[y]<<"\n";
        }
        return 0;
    }
    ll x,y;
    while(q--){
        cin>>x>>y;
        dij(x);
        cout<<dis[y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
