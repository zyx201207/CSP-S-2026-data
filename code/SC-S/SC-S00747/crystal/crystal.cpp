#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = 500005;
int n;
ll a[N], m, s[N];
int main() {
    // xyy
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    std::sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) r = mid;
            else l = mid + 1;
        }
        ans = std::max(ans, i - l + 1);
    }
    printf("%d", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}