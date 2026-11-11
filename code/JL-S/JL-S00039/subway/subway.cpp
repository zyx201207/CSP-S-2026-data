#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=5e5+5;
int c,n,m,d,q;
struct node{
    int v,tm;
};
struct pm{
    int u,dis,op;
    bool operator<(const pm &x)const{
        return dis>x.dis;
    }
};
int vis[maxn][505],dis[maxn][505],ans[5005][5005];
int cd[maxn][505],w[maxn];
vector<node> mp[maxn];
void dij(int s){
    priority_queue<pm> q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(cd[s][i]) dis[s][i]=cd[s][i];
        q.push({s,dis[s][i],i});
    }
    while(!q.empty()){
        int u=q.top().u;
        int op=q.top().op;
        q.pop();
        if(vis[u][op]) continue;
        vis[u][op]=1;
        for(int i=0;i<mp[u].size();i++){
            int v=mp[u][i].v;
            int tm=mp[u][i].tm;
            int sum=(tm!=op)*(cd[u][op]+cd[v][tm]);
            if(dis[u][op]+sum<dis[v][tm]){
                dis[v][tm]=dis[u][op]+sum;
                q.push({v,dis[v][tm],tm});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        int last=0;
        while(t--){
            int x,y;
            cin>>x>>y;
            cd[x][i]=y;
            mp[last].push_back({x,i});
            mp[x].push_back({last,i});
            last=x;
        }
    }
    memset(ans,0x3f,sizeof(ans));
    for(int i=1;i<=m;i++){
        dij(i);
        for(int j=i;j<=m;j++){
            for(int k=1;k<=n;k++){
              if(cd[j][k])   ans[i][j]=min(ans[i][j],dis[j][k]+w[i]+w[j]);
            }

        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        if(u>v) swap(u,v);
        cout<<ans[u][v]<<"\n";
    }
    return 0;
}
