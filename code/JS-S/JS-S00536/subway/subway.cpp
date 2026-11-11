

#include<bits/stdc++.h>
#define ll long long

using namespace std;
int c,m,n,d,q;
ll w[1010];
int a[1010][510];
ll g[1010][510];
bool vis[1010][510];
ll f[1010][510];
struct node{
    int x,p;
    ll w;
};
bool operator<(node a,node b){
    return a.w>b.w;
}
void dij(int s){
    priority_queue<node> q;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[i][j]=0;
            f[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++){
        if(a[s][i]){
            q.push({s,i,g[s][i]});
            f[s][i]=g[s][i];
        }
    }
    while(q.size()){
        node u=q.top();
        q.pop();
        if(vis[u.x][u.p])continue;
        vis[u.x][u.p]=1;
        for(int i=1;i<=n;i++){
            if(a[i][u.p]&&i!=u.x){
                if(f[i][u.p]>f[u.x][u.p]+g[i][u.p]){
                    f[i][u.p]=f[u.x][u.p]+g[i][u.p];
                    q.push({i,u.p,f[i][u.p]});
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(a[u.x][i]&&i!=u.p){
                if(f[u.x][i]>f[u.x][u.p]+g[u.x][i]){
                    f[u.x][i]=f[u.x][u.p]+g[u.x][i];
                    q.push({u.x,i,f[u.x][i]});
                }
            }
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=m;i++){
        int kk;
        cin>>kk;
        for(int j=1;j<=kk;j++){
            int u;
            ll t;
            cin>>u>>t;
            a[u][i]=1;
            g[u][i]=t;
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        dij(a);
        ll mi=1e18;
        for(int i=1;i<=m;i++)mi=min(f[b][i],mi);
        cout<<mi+w[a]+w[b]<<'\n';
    }
    return 0;
}
//Oct31==Dec25?
//m<=510,n<=1000
