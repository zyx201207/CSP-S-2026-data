// crystal

#include <bits/stdc++.h>
using namespace std;
#define int long long

bool mbegin;

const int N = 1e6 + 10;
int gA[N], gSum[N];

bool mend;

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> gA[i];

    sort(gA + 1, gA + n + 1);
    for (int i = 1; i <= n; i++)
        gSum[i] = gSum[i - 1] + gA[i];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while (l <= r) {
            int mid = (l + r) / 2;
            if ((i - mid + 1) * gA[i] - (gSum[i] - gSum[mid - 1]) <= m) r = mid - 1;
            else l = mid + 1;
        } ans = max(ans, i - l + 1);
    }

    cout << ans << endl;

    cerr << abs(&mend - &mbegin) / 1048576.0 << " " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    return 0;
}