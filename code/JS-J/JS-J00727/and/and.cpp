#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool flag[200005];
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    long long ans = 0;
    for (int i = 31; i >= 0; i--) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if(flag[j]) continue;
            cnt += (((1LL << i) & a[j]) > 0);
        }
        //cout << cnt << ' ';
        if (cnt >= m) {
            ans += (1LL << i);
            //cout << i << endl;
            for (int j = 1; j <= n; j++) {
                if(flag[j]) continue;
                if (((1LL << i) & a[j]) == 0) flag[j] = true;
            }
        }
    }
    printf("%lld", ans);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
