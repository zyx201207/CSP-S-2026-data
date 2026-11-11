#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], last[N], sum[N], ans[N];
pair<int, int> dp[N];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n; i >= 1; i--) {
        if (last[a[i]]) {
            dp[i].first = 0, dp[i].second = last[a[i]];
        } else {
            dp[i].first = a[i], dp[i].second = i + 1;
        }
        last[a[i]] = i;
        sum[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        ans[dp[i].first] += sum[i];
        sum[dp[i].second] += sum[i];
    }
    for (int i = 1; i <= m; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
