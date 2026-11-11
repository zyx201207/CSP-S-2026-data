#include <bits/stdc++.h>
using namespace std;

struct node{
    long long le;
    char c;
}b[200005];

struct Node{
    long long len;
    char ch;
}a[200005];

struct NOde{
    long long l;
    char cha;
}c[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i].le >> b[i].c;
    long long cnt = 0, sum = b[1].le;
    char last = b[1].c;
    for (int i = 2; i <= n + 1; i++)
    {
        if (b[i].c != last)
        {
            a[++cnt].len = sum;
            a[cnt].ch = last;
            last = b[i].c;
            sum = b[i].le;
        }
        else sum += b[i].le;
    }
    for (int i = 1; i <= cnt; i++)
        c[i].cha = a[cnt - i + 1].ch, c[i].l = a[cnt - i + 1].len;
    long long ans = 0;
    int j = 1;
    for (int i = 1; i <= cnt; i++)
    {

        long long sum = 0;
        while (j <= cnt && sum <= a[i].len)
        {
            sum += c[j].l;
            if (sum > a[i].len)
            {
                sum -= c[j].l;
                if (c[j].cha != a[i].ch) ans += a[i].len - sum;
                c[j].l = c[j].l - (a[i].len - sum);
                break;
            }
            if (sum <= a[i].len && c[j].cha != a[i].ch) ans += c[j].l;
            j++;
        }
    }
    cout << ans / 2 << "\n";
    return 0;
}

