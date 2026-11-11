#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define dep(i,r,l) for(int i = r; i >= l; i--)
#define lc (idx << 1)
#define rc (idx << 1 | 1)

using namespace std;

int c, n, m, q, d;
int x, y;
const int maxn = 5e5 + 100;
map<int, int> i2z[600];
int bdis[600][600];
int dist[600][600];
int w[maxn], k[maxn], vis[600];
vector<int> a[500], t[500];
vector<int> line[maxn];
vector<pair<int, int> > mp[600];
pair<int, int> pii;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

void dijkstra(){
    int u;
    pair<int, int> npair;
    rep(s,1,n){
        while(!pq.empty()){
            pq.pop();
        }
        rep(i,1,n){
            vis[i] = false;
        }
        rep(j,1,n){
            dist[s][j] = 1e12+7;
        }
        dist[s][s] = 0;
        pii.first = dist[s][s];
        pii.second = s;
        pq.push(pii);
        while(!pq.empty()){
            pii = pq.top();
            pq.pop();
            u = pii.second;
            vis[u] = true;
            if(dist[s][u] < pii.first){
                continue;
            }
            for(auto edg : mp[u]){
                if(vis[edg.first])continue;
                if(dist[s][edg.first] > dist[s][u] + edg.second){
                    dist[s][edg.first] = dist[s][u] + edg.second;
                    npair.first = dist[s][edg.first];
                    npair.second = edg.first;
                    pq.push(npair);
                }
            }
        }
    }
}

void init(){
    rep(i,1,n){
        rep(j,1,n){
            bdis[i][j] = 1e12 + 7;
        }
    }
    int l1, l2;
    rep(i,1,m){
        rep(j,0,((int)line[i].size())-1){
            rep(k,j,((int)line[i].size())-1){
                l1 = line[i][j]; l2 = line[i][k];
                if(line[i][j] == line[i][k])continue;
                if(bdis[l1][l2] > ((t[l1][i2z[l1][i]]) + (t[l2][i2z[l2][i]]))){
                    bdis[l1][l2] = (t[l1][i2z[l1][i]]) + (t[l2][i2z[l2][i]]);
                    bdis[l2][l1] = (t[l1][i2z[l1][i]]) + (t[l2][i2z[l2][i]]);
                }
            }
        }
    }
    rep(i,1,n){
        rep(j,1,n){
            if(bdis[i][j] != 1e12 + 7){
                pii.first = i;
                pii.second = bdis[i][j];
                mp[j].push_back(pii);
                pii.first = j;
                mp[i].push_back(pii);
            }
        }
    }
    dijkstra();
}

void solve(){
    cin >> x >> y;
    int res1 = LONG_LONG_MAX;
    for(int l1 : line[x]){
        for(int l2 : line[y]){
            res1 = min(res1, dist[l1][l2] + t[l1][i2z[l1][x]] + t[l2][i2z[l2][y]]);
        }
    }
    cout << (res1 + w[x] + w[y]) << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    rep(i,1,m){
        cin >> w[i];
    }
    rep(i,1,n){
        cin >> k[i];
        a[i].push_back(-1);
        t[i].push_back(-1);
        rep(j,1,k[i]){
            cin >> x >> y;
            a[i].push_back(x);
            t[i].push_back(y);
            i2z[i][x] = j;
            line[a[i][j]].push_back(i);
        }
    }

    init();

    while(q--){
        solve();
    }

    return 0;
}