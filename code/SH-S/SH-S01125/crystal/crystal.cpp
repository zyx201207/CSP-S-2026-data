#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n, m;
int a[N];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    int ans = 0;
    int diff = 0;
    int len = 1;
    for (int i = 1, j = 1; i <= n; i++) {
        len = i - j + 1;
        diff += (len - 1) * a[i];

        while (diff > m && j <= i) {
            diff += a[j];
            diff -= a[i];
            j++;
        }
        
        len = i - j + 1;
        ans = max(ans, len);
        diff -= (len * a[i]);
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}