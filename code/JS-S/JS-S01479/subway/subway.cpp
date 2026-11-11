#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); i ++ )
#define DF(i, a, b) for (int i = (a); i >= (b); i -- )
inline void chkmin(int& a, int b) { if (a > b) a = b; }
inline void chkmax(int& a, int b) { if (a < b) a = b; }

typedef pair<int,int> PII;

const int N = 1000010, M = N, INF = 1e18;

int c, n, m, d, q;
vector<PII> v[N];
vector<int> node_id[N];
int node_idx;
int dan_id[N], a[N];
int h[N],e[M],ne[M],w[M],idx;
bool st[N];
int dist[N];
int ww=-1;bool f=1;
vector<vector<int>>tmp;

void add(int a,int b,int c){
    if(c!=0) {
        if(ww==-1) ww=c;
        else f&=c==ww;
    }
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

int get_dist(int u,int v ){
    priority_queue<PII,vector<PII>,greater<PII>> q;
    F(i,1,node_idx)dist[i]=INF, st[i]=0;;
    dist[u]=0;
    q.emplace(dist[u],u);
    while(q.size()) {
        auto [tmp, u] = q.top();q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(int i=h[u];~i;i=ne[i]) {
            int j=e[i];
            if(dist[j]>dist[u]+w[i]) {
                dist[j]=dist[u]+w[i];
                q.emplace(dist[j],j);
            }
        }
    }
    return dist[v];
}

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // freopen("subway3.in","r",stdin);
    // freopen("my.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    memset(h, -1, sizeof h);
    F(i, 1, m) cin >> a[i];
    F(i,1,n) {
        int num;cin>>num;
        while(num--) {
            int x,y;cin>>x>>y;
            v[i].emplace_back(x,y);
            node_id[i].push_back(++node_idx);
        }
    }
    F(i,1,m) dan_id[i]=++node_idx;
    F(i,1,n) {
        F(j,0,(int)v[i].size() - 1) {
            int tx=v[i][j].first,ty=v[i][j].second;
            add(node_id[i][j],dan_id[tx],ty);
            add(dan_id[tx],node_id[i][j],ty);
            if(j!=(int)v[i].size()-1) add(node_id[i][j],node_id[i][j+1],0), add(node_id[i][j+1],node_id[i][j],0);
        }
    }
    
    while(q--){
        int x,y; cin>>x>>y;
        cout<<get_dist(dan_id[x],dan_id[y])+a[x]+a[y]<< "\n";
    }
    return 0;
}