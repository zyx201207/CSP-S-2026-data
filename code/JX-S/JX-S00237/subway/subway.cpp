#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int w[500005];
struct edge{
    int to,w;
};
vector<edge> e[500605];
bool vis[500605];
ll dp[500605];
struct node{
    int u;
    ll w;
    bool operator< (const node& other) const{
        return w>other.w;
    }
};
ll dijstra(int l,int r){
    memset(vis,0,sizeof vis);
    memset(dp,0x3f,sizeof dp);
    priority_queue<node> q;
    q.push({l,w[l]+w[r]});
    dp[l]=w[l]+w[r];
    while(!q.empty()){
        node i=q.top();
        if(i.u==r) return dp[r];
        q.pop();
        if(vis[i.u]) continue;
        vis[i.u]=1;
        for(auto j:e[i.u]){
            if(i.w+j.w<dp[j.to]){
                dp[j.to]=i.w+j.w;
                q.push({j.to,dp[j.to]});
            }
        }
    }
}
ll dijstr(int l,int r){
    memset(vis,0,sizeof vis);
    queue<node> q;
    q.push({l,0});
    vis[l]=1;
    while(!q.empty()){
        node i=q.front();
        if(i.u==r) return i.w;
        q.pop();
        for(auto j:e[i.u]){
            if(!vis[j.to]){
                q.push({j.to,i.w+1});
                vis[j.to]=1;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,l,r,k,u,tw,v,cw=0;
    bool fb=1;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        if(k==1) continue;
        v=m+i;
        for(int j=1;j<=k;j++){
            scanf("%d %d",&u,&tw);
            if(cw&&tw!=cw) fb=0;
            cw=tw;
            e[u].push_back({v,tw});
            e[v].push_back({u,tw});
        }
    }
    while(q--){
        scanf("%d %d",&l,&r);
        if(fb) printf("%lld\n",dijstr(l,r)*cw+w[l]+w[r]);
        else printf("%lld\n",dijstra(l,r));
    }
    return 0;
}
