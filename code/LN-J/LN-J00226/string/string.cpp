#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], suml[200005], sumr[200005];
char c[200005];
long long l = 1, r = 0, lin, rin, cnt = 0, rr;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    lin = 1;
    rin = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        r += a[i];
        suml[i] = suml[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--)
    {

        sumr[i] = sumr[i + 1] + a[i];
    }
    n = r;
    while (l <= r)
    {
        rr = n - r + 1;
        if (lin == rin) break;
        if (suml[lin] - l + 1 > sumr[rin] - rr + 1)
        {
            if (c[lin] != c[rin])
            {
                cnt += sumr[rin] - rr + 1;
            }
            l += sumr[rin] - rr + 1;
            r -= sumr[rin] - rr + 1;
            rin--;
        }
        else if (suml[lin] - l + 1 == sumr[rin] - rr + 1)
        {
            if (c[lin] != c[rin])
            {
                cnt += sumr[rin] - rr + 1;
            }
            l += sumr[rin] - rr + 1;
            r -= sumr[rin] - rr + 1;
            rin--;
            lin++;
        }
        else
        {
            if (c[lin] != c[rin])
            {
                cnt += suml[lin] - l + 1;
            }
            l += suml[lin] - l + 1;
            r -= suml[lin] - l + 1;
            lin++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
