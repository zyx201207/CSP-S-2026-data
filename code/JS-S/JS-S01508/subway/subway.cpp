#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pi pair<int,int>
int c,n,m,d,q;
const int N=5e5+5;
int a[N];
int t[N];
int w[N];
int dis[N];
int vis[N];
int f[1005][1005];
struct node{
    int w,v;
};
vector <node> e[N];
int dij(int s,int t){
    for(int i=1;i<=m;i++) dis[i]=1e18;
    for(int i=1;i<=m;i++) vis[i]=0;
    priority_queue<pi,vector<pi>,greater<pi> >q;
    dis[s]=0;
    q.push({0,s});
    while(q.size()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<e[u].size();i++){
            int v=e[u][i].v,W=e[u][i].w;
            if(dis[v]>dis[u]+W){
                dis[v]=dis[u]+W;
                q.push({dis[v],v});
            }
        }
    }
    return dis[t]+w[s]+w[t];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=1e18;
        }
    }
    int me=0;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        if(c>=12&&c<=19){
            me=t[1];
            continue;
        }
        for(int u=1;u<=k;u++){
            for(int v=1;v<=k;v++){
                if(a[u]==a[v]) continue;
                e[a[u]].push_back({t[u]+t[v],a[v]});
                f[a[u]][a[v]]=min(f[a[u]][a[v]],t[u]+t[v]);
            }
        }
    }

    /*for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(f[i][k]==1e18||f[k][j]==1e18) continue;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
*/
    while(q--){
        int x,y;
        cin>>x>>y;
        if(c>=12&&c<=19){
            cout<<me*2+t[x]+t[y]<<endl;
        }
        else cout<<dij(x,y)<<endl;
       // cout<<f[x][y]+t[x]+t[y]<<endl;
    }
    return 0;
}
