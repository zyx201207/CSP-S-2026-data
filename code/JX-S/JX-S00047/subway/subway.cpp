#include <bits/stdc++.h>
#define debug(a) //a
using namespace std;
const int N = 505;
int c, n, m, d, q;
int w[N], a[N], t[N];
struct Node {int to;long long t;bool operator<(Node o)const{return this->t > o.t;}};
vector<Node> g[N];
long long vis[N];
long long l[N][N];
long long search(int x, int y) {
    if (l[x][y]!=0) return l[x][y];
    priority_queue<Node> que;
    que.push({x, w[x] + w[y]});
    for (int i = 1 ; i <= m ; i++) vis[i] = 0xfffffffffffffff;
    while (!que.empty()) {
        if (que.top().t < vis[que.top().to])
        for (auto i : g[que.top().to]) {
            debug(cout<<"check " << i.to << " ";)
            if (vis[i.to] <= que.top().t+i.t) continue;
            if (i.to == y) return que.top().t+i.t;
            que.push({i.to, que.top().t+i.t});
            l[x][i.to] = que.top().t+i.t-w[y]+w[i.to];
            debug(cout << "push " << i.to << "," << que.top().t+i.t << endl;)
        }
        vis[que.top().to] = que.top().t;
        debug(cout << "pop " << que.top().to << "," << que.top().t << endl;)
        que.pop();
    }//*/
    return -1;
}
int main() {
    ifstream cin("subway.in");
    ofstream cout("subway.out");
    cin >> c >> n >> m >> d >> q;
    for (int i = 1 ; i <= m ; i++) cin >> w[i];
    for (int i = 1, k ; i <= n ; i++) {
        cin >> k;
        for (int j = 1, ia, it ; j <= k ; j++) {
            cin >> a[j] >> t[j];
            for (int x = 1 ; x < j ; x++) {
                long long c = t[x]+t[j];
                g[a[x]].push_back({a[j], c});
                g[a[j]].push_back({a[x], c});
                debug(::cout << a[x] << "<" << c << ">" << a[j] << endl;)
            }
        }
    }
    int x, y;
    while (q--) {
        cin >> x >> y;
        debug(::cout << "-----" << x << "->" << y << "-----" << endl;)
        cout << search(x, y) << endl;
    }
    return 0;
}
