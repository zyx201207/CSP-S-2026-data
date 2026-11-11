#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
struct node{
    ll to;
    ll v;
};
ll c,n,m,d,questions;
vector<node> g[N];
ll dist[N];
ll w[N];
bool t[N];
ll x,y;
void init(){
    memset(t,false,sizeof(t));
    t[x]=true;
    for(ll i=1;i<=m+n;i++)dist[i]=LLONG_MAX;
    dist[x]=0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c;
    cin>>n;
    cin>>m;
    cin>>d;
    cin>>questions;
    vector<ll> w(m+1);
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(ll j=1;j<=k;j++){
            ll a,t;
            cin>>a>>t;
            g[a].push_back({m+i,t});
            g[m+i].push_back({a,t});
        }
    }
    while(questions--){
        cin>>x>>y;
        ll ans=w[x]+w[y];
        init();
        queue<ll> q;
        q.push(x);
        while(!q.empty()){
            ll u=q.front();
            q.pop();
            t[u]=false;
            for(node v:g[u]){
                ll tt=v.to,vv=v.v;
                if(dist[tt]>vv+dist[u]){
                    dist[tt]=dist[u]+vv;
                    if(!t[tt]){
                        q.push(tt);
                        t[tt]=true;
                    }
                }
            }
        }
        cout<<dist[y]+ans<<endl;
    }
    return 0;
}
