#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
long long ans = 0;
int n;
pair<int, char> a[N];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1, j = n; i <= n; i++) {
        while (i != j && a[i].first > 0) {
            int mn = min(a[i].first, a[j].first);
            a[i].first -= mn, a[j].first -= mn;
            if (a[i].second != a[j].second) ans += mn;
            if (!a[j].first) j--;
        }
        if (i == j) break;
    }
    printf("%lld\n", ans);
    return 0;
}
