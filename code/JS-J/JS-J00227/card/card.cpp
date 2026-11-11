#include <bits/stdc++.h>
using namespace std;

int last[300010];
int n;
int m;
int a[500010];
int pre[500010];
int cnt[300010];
int sum[500100];
signed main() {
    freopen("card.in", "a+", stdin);
    freopen("card.out", "w+", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = last[a[i]];
        last[a[i]] = i;
        sum[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        int now = i;
        if (now != last[a[now]]) continue;
        int t = sum[a[now]];
        while (now <= n) {
            cnt[a[now]] += t;
            now = last[a[now]] + 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
    }

    return 0;
}