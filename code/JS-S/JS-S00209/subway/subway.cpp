#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxd=22;
const int maxn=502;
const int maxm=5e5+2;
int c,n,m,d,q,INF;
int e[maxn][maxn],dis[maxn][maxn];
bool vis[maxn];
struct line{
    int id,t;   //the idth line's station need t time
};
struct station{
    int w; //cn:there are how many lines in this station; w:the original one
    vector<line> ln;
}a[maxm];
void bfs(int st){
    memset(vis,false,sizeof(vis));
    queue<line> q;
    vis[st]=true;
    dis[st][st]=0;
    q.push({st,0});
    while(!q.empty()){
        line cur=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(e[cur.id][i]<INF&&(!vis[i]||cur.t+e[cur.id][i]<dis[st][i])){
                vis[i]=true;
                dis[st][i]=cur.t+e[cur.id][i];
                q.push({i,dis[st][i]});
            }
        }
    }
}
void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<' ';
        }
        cout<<'\n';
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    memset(e,0x3f,sizeof(e)); INF=e[1][1];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i].w;
    }
    for(int i=1;i<=n;i++){
        int k,pos,tim;
        cin>>k;
        while(k--){
            cin>>pos>>tim;
            a[pos].ln.push_back({i,tim});
        }
    }
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
    for(int i=1;i<=n;i++) e[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<a[i].ln.size()-1;j++){
            int x=a[i].ln[j].id;
            for(int k=j+1;k<a[i].ln.size();k++){
                int y=a[i].ln[k].id;
                e[x][y]=e[y][x]=min(e[x][y],a[i].ln[j].t+a[i].ln[k].t);
            }
        }
    }
    for(int i=1;i<=n;i++) bfs(i);
    // print();    // checking the code
    while(q--){
        int x,y,ans=1e18;
        cin>>x>>y;
        for(auto u:a[x].ln){
            for(auto v:a[y].ln){
                ans=min(ans,dis[u.id][v.id]+a[x].w+u.t+a[y].w+v.t);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
