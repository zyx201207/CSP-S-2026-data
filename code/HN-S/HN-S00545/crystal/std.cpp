#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5, inf = 1e18;
int n, m, a[N], res;
unordered_map<int, int> cnt;
inline void dfs(int p) {
    if(p > m) {
        cnt.clear();
        for(int i = 1; i <= n; i++) cnt[a[i]]++;
        for(auto [x, y] : cnt) res = max(res, y);
        return;
    }
    for(int i = 1; i <= n; i++) {
        a[i]++, dfs(p + 1), a[i]--;
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dfs(1);
    cout << res;
    return 0;
}
/*
乐扣保佑！！！！！！
*/