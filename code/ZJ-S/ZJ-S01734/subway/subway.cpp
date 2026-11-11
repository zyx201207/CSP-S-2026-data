#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
const int N = 505;
const int M = 5E5+10;
const int inf = 0x3f3f3f3f3f3f3f3f;
struct edge{
    int next, x;
    edge(int tn, int tx):next(tn),x(tx){}
};
struct node {
    int val, now, px;
    bool operator>(const node &b)const {
        return val > b.val;
    }
    node(int v, int n, int p):val(v),now(n),px(p){}
};
int c,n,m,d,q,w[M],x,y;
vector<int> a[M],t[M];
vector<edge> g[M];
map<int, int> xt[M];
vector<int> gx[M];
int dis[M], lst = 0;
int solve() {
    for(int i=1;i<=m;i++) dis[i] = inf;
    dis[m+2]=inf;
    priority_queue<node, vector<node>, greater<node>> q;
    dis[m+1] = 0;
    q.push(node(0, m+1, 0));
    g[m+1].clear();
    for(const int &i:gx[x])g[m+1].push_back(edge(x, i));
    for(const int &i:gx[y])g[y].push_back(edge(m+2, -1)), lst++;
    while(!q.empty()) {
        node cur = q.top(); q.pop();
        for(const edge &i:g[cur.now]) {
            int v = (i.x == -1 ? xt[cur.px][cur.now] : cur.px == 0 ? xt[i.x][i.next] : cur.px == i.x ? 0 : xt[cur.px][cur.now] + xt[i.x][cur.now]);
            if (dis[i.next] > dis[cur.now] + v) {
                dis[i.next] = dis[cur.now] + v;
                q.push(node(dis[i.next], i.next, i.x));
            }
        }
    }
    return dis[m+2]+w[x]+w[y];
}
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) {
        cin >> w[i];
    }
    int ta, tt, tk;
    for(int i=1;i<=n;i++) {
        cin >> tk;
        t[i].push_back(0);
        while(tk -- ) {
            cin>>ta>>tt;
            a[i].push_back(ta);
            gx[ta].push_back(i);
            t[i].push_back(tt);
            xt[i][ta] = tt;
        }
    }
    for(int i=1;i<=n;i++) {
        int tk=a[i].size();
        for(int j=0;j<tk-1;j++) {
            g[a[i][j]].push_back(edge(a[i][j+1], i));
        }
    }
    while(q -- ) {
        cin >> x >> y;
        cout << solve() << '\n';
        while(lst--) g[y].pop_back();
        lst = 0;
    }


    return 0;
}