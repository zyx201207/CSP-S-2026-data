#include <iostream>
#include <climits>
using namespace std;

constexpr int N = 2e5 + 1;
int n, m;
int a[N];
bool vis[N];

int dfs(int l, int dep) {
    if (dep > m) {
        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            if (vis[i] == 0) {
                continue;
            }
            ans &= a[i];
        }
        return ans;
    }
    int ans = 0;
    for (int i = l; i <= n; ++i) {
        vis[i] = 1;
        ans = max(ans, dfs(i + 1, dep + 1));
        vis[i] = 0;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cout << dfs(1, 1) << '\n';
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}