#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,qu,dist[1510][1510],head[400400],cnt=0;
ll w[500010];
bool vis[1510][1510],viss[1510];
struct node{
    ll to,next,w;
}a[400400];
struct ele{
    ll u,d;
    friend bool operator<(ele a,ele b){
            return a.d>b.d;
    }
}heap[400400];
priority_queue <ele> q;
void init(){
    cnt=0;
    memset(dist,0x3f,sizeof dist);
    memset(head,-1,sizeof head);
    memset(vis,false,sizeof vis);
    memset(viss,false,sizeof viss);
}
void add(ll u,ll v,ll w){
    cnt++;
    a[cnt].next=head[u];
    a[cnt].to=v;
    a[cnt].w=w;
    head[u]=cnt;
}
void Dj(ll s){
    dist[s][s]=0;
    vis[s][s]=true;
    while(!q.empty()) q.pop();
    q.push({s,0});
    while(!q.empty()){
        ele cur=q.top();
        q.pop();
        for(ll i=head[cur.u];i!=-1;i=a[i].next){
            ll v=a[i].to,w=a[i].w;
    //        cout<<"check"<<dist[s][v]<<' '<<cur.d<<' '<<w<<endl;
            if(!vis[s][v]&&dist[s][v]>cur.d+w){
                dist[s][v]=w+cur.d;
                q.push({v,dist[s][v]});
                vis[s][v]=true;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin>>c>>n>>m>>d>>qu;
    for(ll i=1;i<=m;i++) cin>>w[i];
    for(ll i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(ll j=1;j<=k;j++){
            ll ak,tk;
            cin>>ak>>tk;
            add(m+i,ak,tk);
            add(ak,m+i,tk);
        }
    }
    while(qu--){
        ll x,y;
        cin>>x>>y;
        if(!viss[x]) Dj(x);
        viss[x]=true;
        cout<<dist[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
