#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll v,w;
};
const ll INF=1<<31-1;
vector<node>p[501001];
ll w[500001],dis[501001];
bool vis[501001];
ll c,n,m,d,qqq;
ll solve(ll s,ll t){
    for(int i=1;i<=n+m;i++){dis[i]=INF;vis[i]=0;}
    queue<ll> q;
    q.push(s);dis[s]=0;
    while(!q.empty()){
        ll x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=0;i<p[x].size();i++){
            if(dis[p[x][i].v]>dis[x]+p[x][i].w){
                if(p[x][i].v!=t&&vis[p[x][i].v]==0){q.push(p[x][i].v);vis[p[x][i].v]=1;}
                dis[p[x][i].v]=dis[x]+p[x][i].w;
            }
        }
    }
    return dis[t];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>qqq;
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        ll k;cin>>k;
        for(ll j=1;j<=k;j++){
            ll a,t;cin>>a>>t;
            node x;
            x.v=a;x.w=t;
            p[i+m].push_back(x);
            x.v=i+m;
            p[a].push_back(x);
        }
    }
    while(qqq--){
        ll x,y;cin>>x>>y;
        cout<<solve(x,y)+w[x]+w[y];
        if(qqq>0)cout<<'\n';
    }
    return 0;
}
