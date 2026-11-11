#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int n, c1, c2, sum, ans;
struct node
{
    int a;
    char c;
} a[N], a1[N], a2[N];

void init()
{
    int l = 0, r = 0, ii = 0;
    for (int i = 1; i <= n; i++)
    {
        if (l + a[i].a <= sum / 2)
        {
            if (a[i].c == a1[c1].c) a1[c1].a += a[i].a;
            else a1[++c1] = a[i];
            l += a[i].a;
        }
        else
        {
            int k = sum / 2 - l;
            if (a[i].c == a1[c1].c) a1[c1].a += k;
            else a1[++c1] = {k, a[i].c};
            l += k, ii = i, a[i].a -= k;
            break;
        }
    }
    for (int i = n; i >= ii; i--)
    {
        if (a[i].c == a2[c2].c) a2[c2].a += a[i].a;
        else a2[++c2] = a[i];
    }
    if (a1[c1].a == 0) c1--;
    if (sum % 2 == 1) a2[c2].a--;
    for (int i = 1; i <= c1; i++) a1[i].a += a1[i - 1].a;
    for (int i = 1; i <= c2; i++) a2[i].a += a2[i - 1].a;
}

void solve()
{
    int now = 0, l = 1, r = 1;
    while (1)
    {
        if (a1[l].c == a2[r].c)
        {
            if (a1[l].a < a2[r].a) now = a1[l].a, l++;
            else if (a1[l].a > a2[r].a) now = a2[r].a, r++;
            else now = a1[l].a, l++, r++;
        }
        else
        {
            if (a1[l].a < a2[r].a) ans += a1[l].a - now, now = a1[l].a, l++;
            else if (a1[l].a > a2[r].a) ans += a2[r].a - now, now = a2[r].a, r++;
            else ans += a1[l].a - now, now = a1[l].a, l++, r++;
        }
        if (l > c1 && r > c2) return ;
    }
}

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].a >> a[i].c, sum += a[i].a;
    init(), solve();
    cout << ans;
    return 0;
}
