#include <bits/stdc++.h>
#define debug(a) a
using namespace std;
const int N = 2e6+5;
int c, t, n, d;
long long x[N];
vector<int> g[N];
long long vis[N], l[N];
long long search() {
    long long ret = 0;
    for (int i = 1 ; i <= n ; i++) {vis[i]=0;l[i]=3;}
    for (int i = 1 ; i <= n ; i++) {
        queue<pair<int, int>> que;
        que.push({i, 0});
        while (!que.empty()) {
            auto top = que.front();
            debug(cout << "|" << top.first << ":" << top.second << "\n";)
            for (int j : g[top.first]) {
                if (l[j]<top.second+1) continue;
                vis[j]++;
                if (l[i]==top.second+1) continue;
                l[j]=top.second+1;vis[j]=1;
                que.push({j, top.second+1});
            }
            que.pop();
        }
        for (int j = i+1 ; j <= n ; j++) {
            debug(cout << l[j] << ":" << vis[j] << " ";)
            if (vis[j]==2&&l[j]==2) ret++;
        }
        debug(cout << endl;)
    }
    return ret;
}
int main() {
    ifstream cin("migrate.in");
    ofstream cout("migrate.out");
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1 ; i <= n ; i++) cin >> x[i];
        for (int i = 1 ; i <= n ; i++) {
            g[i].clear();
            for (int j = i+1 ; j <= n ; j++) {
                if (x[j]-x[i]>d)break;
                g[i].push_back(j);
            }
        }
        cout << search() << endl;
    }
    return 0;
}
