#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e6+505;
class node{
public:
    int v,val;
    friend bool operator<(node a,node b){return a.val>b.val;}
    node():v(0),val(0){};
    node(int a,int b):v(a),val(b){};
};
vector<node>e[MAXN];
int c,n,m,d,q,cnt;
int w[MAXN],dis[MAXN];
bool vis[MAXN];
map<pair<int,int>,int>di;
void add(int u,int v,int val){
    e[u].push_back(node(v,val));
    e[v].push_back(node(u,val));
}
int dij(int u,int v){
    memset(vis,0,sizeof(int)*(n+m+1));
    memset(dis,0x3f,sizeof(int)*(n+m+1));
    priority_queue<node>q;
    q.push(node(u,0));
    dis[u]=0;
    while(!q.empty()){
        int cur=q.top().v,we=q.top().val;
        q.pop();
        if(cur==v)return dis[v];
        if(vis[cur])continue;
        vis[cur]=1;
        for(auto i:e[cur])
            if(dis[cur]+i.val<dis[i.v]){
                dis[i.v]=dis[cur]+i.val;
                q.push(node(i.v,dis[i.v]));
            }
    }
}
void solve(){
    cin>>c>>n>>m>>d>>q;
    cnt=m;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        cnt++;
        for(int j=1;j<=k;j++){
            int u,val;
            cin>>u>>val;
            add(cnt,u,val);
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        if(u==v)cout<<0<<'\n';
        else if(!di[{u,v}]){
            di[{u,v}]=di[{v,u}]=dij(u,v)+w[u]+w[v];
            cout<<di[{u,v}]<<'\n';
        }else cout<<di[{u,v}]<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    solve();
    return 0;
}
