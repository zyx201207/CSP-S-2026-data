#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, t;
long long a[N];
int ans, sum, n, m;
void solve1 (int s, int e, int num) {
    if (s == e) {
        if (num < ans){
            ans = num;
            sum = 0;
        }
        if (num == ans) sum++;
        return;
    }
    for (int i = s + 1; i <= e; i++) {
        if(a[i]-a[s]<=m) solve1 (i, e, num + 1);
    }
}
int main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int cnt = 0;
        ans = INT_MAX,  sum = 0;
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= i - 3; j++) {
                ans = INT_MAX, sum = 0;
                solve1(j, i, 0);
                if (sum == 2) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}