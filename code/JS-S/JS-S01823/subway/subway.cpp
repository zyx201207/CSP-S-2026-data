#include <bits/stdc++.h>
using namespace std;

struct Node{
    int a;
    long long b;
};

int c,n,m,d,q;
int head[1000005],next[1000005];
long long a[1000005];
long long dis[1005][1005];
vector<Node> G[500005];
vector<int> g[1005];
long long v[505];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++) {
        cin >> a[i];
    }
    for(int i = 0;i <= n;i ++) {
        for(int j = 0;j <= n;j ++) {
            dis[i][j] = 100000000000;
        }
    }
    for(int i = 1;i <= n;i ++) {
        int k;
        cin >> k;
        for(int j = 0;j < k;j ++) {
            int u;
            long long wei;
            cin >> u >> wei;
            Node tmp;
            tmp.a = i;
            tmp.b = wei;
            //G[u].push_back(i + n);
            G[u].push_back(tmp);
            /*
            dis[u][i + m] = wei;
            dis[i + m][u] = wei;
            */
        }
    }
    for(int i = 1;i <= m;i ++) {
        for(Node j : G[i]) {
            for(Node k : G[i]) {
                if(j.a == k.a) {
                    dis[j.a][k.a] = 0;
                } else {
                    dis[j.a][k.a] = min(dis[j.a][k.a],j.b + k.b);
                }
            }
        }
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            for(int k = 1;k <= n;k ++) {
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q --) {
        long long res = 10000000000;
        int x,y;
        cin >> x >> y;
        for(Node i : G[x]) {
            for(Node j : G[y]) {
                res = min(res,dis[i.a][j.a] + i.b + j.b);
                //cout << dis[i.a][j.a] << ' ';
            }
        }
        cout << res + a[x] + a[y] << endl;
    }
    return 0;
}
