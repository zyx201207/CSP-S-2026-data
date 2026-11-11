#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 5e5 + 1010;
int c,n,m,d,qq;
int w[N],x[N],y[N];
struct node{
    int t,nex,w;
}e[N << 1];
int head[N],tot,ans[N],dis[N];
bool vis[N];
void add(int x,int y,int w){
    e[++tot].t = y;
    e[tot].nex = head[x];
    e[tot].w = w;
    head[x] = tot;
}
struct Node{
    int x,w;
};

bool operator<(Node x,Node y){
    return x.w > y.w;
}priority_queue<Node> q;
void dijistra(int s){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    q.push(Node{s,0});
    while(!q.empty()){
        Node x = q.top();
        q.pop();
        vis[x.x] = 0;
        for (int i = head[x.x]; i ; i = e[i].nex){
            int v = e[i].t;
            if (dis[v] > dis[x.x] + e[i].w){
                dis[v] = dis[x.x] + e[i].w;
                if (!vis[v]){
                    q.push(Node{v,dis[v]});
                    vis[v] = 1;
                } 
            }
        }
    }
}
void bfs(int s){
    queue<int> p;
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    p.push(s);
    while(!p.empty()){
        int u = p.front();
        p.pop();
        vis[u] = 1;
        for (int i = head[u]; i ; i = e[i].nex){
            int v = e[i].t;
            if (vis[v] == 1) continue;
            dis[v] = dis[u] + e[i].w;
            p.push(v);
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(ans,0x3f3f3f,sizeof(ans));
    cin >> c >> n >> m >> d >> qq;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++){
            int a,t;
            cin >> a >> t;
            add(a,i + m,t);
            add(i + m,a,t);
        }
    }
    for (int i = 1; i <= qq; i++) cin  >> x[i] >> y[i];
    for (int i = m + 1; i <= m + n; i++){
        if (12 <= c && c <= 19) bfs(i);
        else dijistra(i);
        for (int j = 1; j <= qq; j++){
            ans[j] = min(ans[j],dis[x[j]] + dis[y[j]] + w[x[j]] + w[y[j]]);
        }

    }
    for (int i = 1; i <= qq; i++) cout << ans[i] << "\n";
    return 0;
}