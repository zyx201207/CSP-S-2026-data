#include <bits/stdc++.h>

using namespace std;
#define int long long
struct node
{
    int x;
    char c;
}a[200010];
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int last = n, len = 0, cnt = 0, ans = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].c;
    for (int i = 1; i <= n; ++i) len += a[i].x;
    for (int i = 1; i <= n; ++i)
    {
        int szdf = 0;
        if (!a[i].x) break;
        cnt += a[i].x;
        if (len % 2 != 0 && cnt > len / 2) --a[i].x;
        if (a[last].c != a[i].c || a[last].x < a[i].x)
        {
            int sum = 0;
            for (int j = last; j >= i && sum < a[i].x; --j)
            {
                if (sum + a[j].x > a[i].x)
                {
                    if (a[j].c != a[i].c || (a[j].c == a[i].c && !a[i].x)) ans += a[i].x - sum;
                    a[j].x -= a[i].x - sum, sum = a[i].x, szdf = j;
                    break;
                }
                sum += a[j].x;
                if (a[j].c != a[i].c || (a[j].c == a[i].c && !a[i].x))ans += a[j].x;
                a[j].x = 0, last = j - 1, szdf = j;
            }
        }
        else if (a[last].c == a[i].c && a[last].x >= a[i].x) a[last].x -= a[i].x;
        if ((len % 2 != 0 && cnt > len / 2) || (len % 2 == 0 && cnt == len / 2)) break;
    }
    cout << ans << endl;
    return 0;
}
