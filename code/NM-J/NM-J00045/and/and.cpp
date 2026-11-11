#include <bits/stdc++.h>
using namespace std;
int n, m;
long long arr[200005], maxm = 0;
bool cnt[35][200005] = {false};
bool vis[200005] = {false};
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        maxm = max(maxm, arr[i]);
        for (int j = 1; j <= 31; j++) {
            if (arr[i] & (1 << (j - 1))) {
                cnt[j][i] = true;
            }
        }
    }
    memset(vis, true, sizeof(vis));
    for (int i = log2(maxm) + 1; i >= 1; i--) {
        int numCnt = 0;
        for (int j = 1; j <= n; j++) {
            if (cnt[i][j] && vis[j]) { numCnt++; }
        }
        if (numCnt >= m) {
            for (int j = 1; j <= n; j++) {
                if (!cnt[i][j]) {
                    vis[j] = false;
                }
            }
        }
    }
    long long ans = 0, mCnt = 1, startIdx = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            ans = arr[i];
            startIdx = i;
            break;
        }
    }
    for (int i = startIdx + 1; i <= n; i++) {
        if (mCnt >= m) {
            cout << ans;
            return 0;
        }
        if (vis[i]) {
            ans &= arr[i];
            mCnt++;
        }
    }
    if (mCnt >= m) {
        cout << ans;
        return 0;
    }
    cout << 0;
    return 0;
}
