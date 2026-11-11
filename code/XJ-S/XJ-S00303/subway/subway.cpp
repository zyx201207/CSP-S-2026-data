#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,m,n,d,q,cnt,a[N],vis[N];
long long w[N],t[N],dis[N],ans;
struct node{
    int v;
    long long w;
    friend bool operator<(const node &a,const node &b){
        return a.w>b.w;
    }
};
vector<node> e[N];
void add(int u,int v,int w){
    e[u].push_back((node){v,w});
    e[v].push_back((node){u,w});
    return ;
}
void dij(int s,int t){
    priority_queue<node> q;
    for(int i=1;i<=cnt;i++) dis[i]=2e18;
    memset(vis,0,sizeof(vis));
    q.push((node){s,0}),dis[s]=0;
    while(!q.empty()){
        node now=q.top();
        int u=now.v;
        q.pop();
        if(u==t)
            return ;
        if(vis[u]) continue;
        vis[u]=1;
        for(node x:e[u]){
            if(dis[x.v]>x.w+dis[u]){
                dis[x.v]=x.w+dis[u];
                q.push((node){x.v,dis[x.v]});
            }
        }
    }
}
int main(){
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    cnt=m;
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++)
            cin>>a[j]>>t[j];
        for(int j=1;j<=k;j++){
            add(a[j],++cnt,t[j]);
            if(j>1) add(cnt-1,cnt,0);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        dij(x,y);
        ans=w[x]+w[y]+dis[y];
        cout<<ans<<"\n";
    }
    return 0;
}
