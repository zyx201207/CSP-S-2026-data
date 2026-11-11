#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m, a[500005];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    sort(a, a + n);
    int l = 0, r = 1, ans = 1;
    long long sum = 0;
    while (l < r)
    {
        if (sum <= m && r < n && (a[r] - a[r - 1]) * (r - l) <= m - sum)
            sum += (a[r] - a[r - 1]) * (r++ - l);
        else
        {
            ans = max(ans, r - l);
            sum -= a[r - 1] - a[l++];
        }
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
