#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m;
vector<int> g[32];
void get_bit(int x) {
    int p = x;
    int cnt = 1;
    while (x) {
        if (cnt == 32) break;
        if (x & 1) g[cnt].push_back(p);
        x >>= 1;
        cnt++;
    }
}
bool cmp(int a,int b) {
    return a > b;
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;++i) {
        int x;
        cin >> x;
        get_bit(x);
    }
    int maxs = 0;
    for (int i=1;i<=31;++i) {
        if (g[i].size() >= m) maxs = i;
    }
    sort(g[maxs].begin(),g[maxs].end(),cmp);
    int ans = g[maxs][0];
    for (int i=0;i<m;++i) ans = ans & g[maxs][i];
    cout << ans;
    return 0;
}
