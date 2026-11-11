#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,q,num;
const int maxn = 1e3 + 10;
int vis[maxn][maxn];
struct node{
    int to,val;
};
const int inf = 1e18;
vector<node>v[maxn];
int dis[maxn][maxn],w[maxn];
pair<int,int>ph[maxn][maxn];
int cnt[maxn];
void init() {
    for(int i = 1 ; i <= num ; i ++) {
        for(int j = 1 ; j <= num ; j ++) {
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = inf;
        }
    }
    for(int i = 1 ; i <= num ; i ++) {
        for(auto itr:v[i]) {
            int x = itr.to;
            dis[i][x] = min(dis[i][x],itr.val);
        }
    }

    for(int k = 1 ; k <= num ; k ++) {
        for(int i = 1 ; i <= num ; i ++) {
            for(int j = 1 ; j <= num ; j ++) {
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
}
//n zhanshu m xianshu
int query(int x,int y) {
    return dis[x][y] + w[x] + w[y];
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int C;
    cin >> C >> m >> n >> d >> q;
    for(int i = 1 ; i <= n ; i ++) cin >> w[i];
    int num = n;
    for(int i = 1 ; i <= m ; i ++) {
        int x;
        cin >> x;
        for(int j = 1;  j <= x; j  ++) {
            int a,b;
            cin >> a >> b;
            if(j > 1) v[num].push_back({num + 1,0});
            v[a].push_back({++ num,b});
            v[num].push_back({a,b});
            ph[a][++ cnt[a]] = {num,b};
        }
    }
    for(int i = 1 ; i <= n ; i ++) {
        for(int j = 1 ; j <= cnt[i] ; j ++) {
            for(int k = 1 ; k <= cnt[i] ; k ++) {
                if(k == j) continue;
                int x = ph[i][j].first,y = ph[i][k].first;
                int vx = ph[i][j].second,vy = ph[i][k].second;
                v[x].push_back({y,vx + vy});
                v[y].push_back({x,vx + vy});
            }
        }
    }
    init();
    while(q --) {
        int x,y;
        cin >> x >> y;
        cout << query(x,y) << '\n';
    }

    return 0;
}
