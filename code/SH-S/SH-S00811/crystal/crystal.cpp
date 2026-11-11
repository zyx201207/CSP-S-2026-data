#include <bits/stdc++.h>
using namespace std;

int n, ans;
long long m, a[500005], s[500005];

bool check(int start, int end) {
	return (end - start + 1) * a[end] - (s[end] - s[start-1]) <= m;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid, i))
                r = mid;
            else
            	l = mid + 1;
        }
		ans = max(ans, i - l + 1); 
    }
    printf("%d\n", ans);
    return 0;
}
