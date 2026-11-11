#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define F1 freopen("subway.in","r",stdin)
#define F2 freopen("subway.out","w",stdout)
void io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
struct Node{
    ll to,w;
    bool operator <(const Node x){
        return x.w<w;
    }
};
ll c,n,m,d,q,o[500000+100],k[500+100],sum;
vector<ll>s[500+100];
vector<Node>mp[500000+100];
ll dis[500000+100];
bool st[500000+100];

void dijk(ll start){
    memset(dis,0x3f,sizeof(dis));
    memset(st,false,sizeof(st));
    priority_queue<ll,vector<ll>,greater<ll>>q;
    q.push(start);
    dis[start]=0;
    st[start]=true;
    while(!q.empty()){
        auto u=q.top();
        q.pop();
        for(auto &&d:mp[u]){
            if(dis[u]+d.w<dis[d.to]){
                dis[d.to]=dis[u]+d.w;
                st[d.to]=true;
                q.push(d.to);
            }
        }
    }
}
int main(){
    F1;F2;
    io();
    cin>>c>>n>>m>>d>>q;sum=n;
    for(int i=1;i<=m;i++)cin>>o[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        sum+=k[i];
        for(int j=1;j<=k[i];j++){
            ll a,t;
            cin>>a>>t;
            a+=n;
            mp[i].push_back({a,t});
            mp[a].push_back({i,t});
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        if(x==y){
            cout<<0<<endl;
            continue;
        }
        dijk(x+n);
        cout<<o[x]+o[y]+dis[y+n]<<endl;
    }
    return 0;
}
//RP++;CSP-S 132-140pts ->>ag
