#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c[N];
int ans[N];
int n,m;
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    bool flag = 1;
    for (int i=1;i<=n;++i) {
        cin >> c[i];
        if (c[i] < c[i - 1]) flag = 0;
    }
    if (flag) {
        unordered_map<int,int> vis;
        for (int i=1;i<=n;++i) vis[c[i]]++;
        for (int i=1;i<=m;++i) {
            vis[i] += vis[i - 1];
        }
        for (int i=1;i<=m;++i) cout << vis[i] << ' ';
        return 0;
    }
    for (int i=1;i<=n;++i) {
        unordered_map<int,int> vis;
        for (int j=i;j<=n;++j) {
            if (vis.find(c[j]) != vis.end()) {
                int p = vis[c[j]];
                for (int k=j-1;k>=p;--k) vis.erase(c[k]);
            }
            vis[c[j]] = j;
        }
        for (auto j : vis) {
            ans[j.first]++;
        }
    }
    for (int i=1;i<=m;++i) cout << ans[i] << ' ';
    return 0;
}
