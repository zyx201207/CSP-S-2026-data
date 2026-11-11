#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define PII pair<ll,int>
struct edge{
    int to,nxt;
    ull val;
};
priority_queue<PII,vector<PII>,greater<PII>> q;
int c,t;
int n;
int head[5005],tot;
ull d,ans;
ll x[5005];
ull dis[5005],sum[5005];
bool vis[5005];
edge g[12500005];
inline void add(int u,int v,ll w){
    g[++tot].to=v;
    g[tot].nxt=head[u];
    head[u]=tot;
    g[tot].val=w;
}
void init(){
    tot=0;
    memset(head,0,sizeof(head));
}
void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    while (!q.empty()) q.pop();
    for (int i=1;i<=n;i++){
        vis[i]=0;
        sum[i]=1;
    }
    dis[s]=0;
    q.push(make_pair(0,s));
    while (!q.empty()){
        int u=q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=head[u];i;i=g[i].nxt){
            if (!vis[g[i].to]){
                int v=g[i].to;
                ull w=g[i].val;
                if (dis[v]>dis[u]+w){
                    sum[v]=1;
                    dis[v]=dis[u]+w;
                    q.push(make_pair(dis[v],v));
                }else if (dis[v]==dis[u]+w){
                    sum[v]+=sum[v]*sum[u];
                }
            }
        }
    }
}
void calc(int i){
    dij(i);
    for (int v=1;v<=n;v++){
        if (dis[v]!=dis[0]&&sum[v]-1==2){
            // cout << v << ' ';
            ans++;
        }
    }
    // cout << endl << endl;
}

int main (){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while (t--){
        init();
        cin >> n;
        cin >> d;
        for (int i=1;i<=n;i++){
            cin >> x[i];
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                if (x[j]-x[i]<=d){
                    add(i,j,x[j]-x[i]);
                }
            }
        }
        for (int i=1;i<=n-2;i++){
            calc(i);
        }
        cout << ans << '\n';
        ans=0;
    }
    return 0;
}