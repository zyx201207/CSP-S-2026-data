#include <bits/stdc++.h>
using namespace std;

int n, l, r;

unsigned long long ans, mc, cc, cnt;

struct Yuanshen
{
    int num;
    char c;
}a[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].num >> a[i].c;
        cc += a[i].num;
    }
    if (cc % 2 == 0)
    {
        mc = cc / 2;
    }
    else
    {
        cc--;
        mc = cc / 2;
    }
    l = 1;
    r = n;
    while (mc--)
    {
        if (a[l].c != a[r].c)
        {
            ans += min(a[l].num, a[r].num);
        }
        mc -= min(a[l].num, a[r].num);
        mc++;
        a[l].num -= min(a[l].num, a[r].num);
        a[r].num -= min(a[l].num, a[r].num);
        if (a[l].num == 0) l++;
        if (a[r].num == 0) r--;
    }
    cout << ans;
    return 0;
}
/*
8:50
oh no it's so difficult
9:00
mo ni?
9:06
ok, mo ni is TLE
9:10
wait why i don't have a you hua
9:16
wow
9:17
AC

genshin is great
genshin uid:forget either

9:26
wait wait wait
I don't write the freopen
*/
