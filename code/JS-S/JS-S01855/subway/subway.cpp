#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
#define PII pair<ll,pair<int,int>>
priority_queue<PII,vector<PII>,greater<PII>> q;
struct node{
    int to;
    int num;
};
int c,n,m,d,Q,S,T;
ll w[500005],k[505];
ll dis[500005];
int lst[500005];
bool vis[500005];
ll t[20005][505];
int a[20005][505];
vector<node> g[400005];
void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    while (!q.empty()) q.pop();
    dis[s]=0;
    q.push(make_pair(0,make_pair(s,0)));
    while (!q.empty()){
        int u=q.top().second.first,num=q.top().second.second;
        q.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=0;i<g[u].size();i++){
            if (!vis[g[u][i].to]){
                int v=g[u][i].to;
                ll extra=(g[u][i].num!=num)?(t[num][u]+t[g[u][i].num][u]):0;
                if (dis[v]>dis[u]+extra){
                    dis[v]=dis[u]+extra;
                    lst[v]=g[u][i].num;
                    q.push(make_pair(dis[v],make_pair(v,g[u][i].num)));
                }
            }
        }
    }
}

int main (){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> Q;
    for (int i=1;i<=m;i++){
        cin >> w[i];
    }
    for (int i=1;i<=n;i++){
        cin >> k[i];
        for (int j=1;j<=k[i];j++){
            cin >> a[i][j] >> t[i][a[i][j]];
        }
        g[a[i][1]].push_back(node{a[i][2],i});
        g[a[i][k[i]]].push_back(node{a[i][k[i]-1],i});
        for (int j=2;j<=k[i]-1;j++){
            node tmp;
            tmp.num=i;
            tmp.to=a[i][j-1];
            g[a[i][j]].push_back(tmp);
            tmp.to=a[i][j+1];
            g[a[i][j]].push_back(tmp);
        }
    }
    while (Q--){
        cin >> S >> T;
        dij(S);
        cout << dis[T] << ' ' << w[S] << ' ' << w[T] << ' ' << t[lst[T]][T] << ' ' << lst[T] << ' ' << endl;
        cout << dis[T]+w[S]+w[T]+t[lst[T]][T] << endl;
    }
    return 0;
}