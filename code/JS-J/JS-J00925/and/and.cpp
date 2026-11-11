#include <bits/stdc++.h>
using namespace std;

int n, m, a[200005], mn, maxn = -1e9, mi = 0;
bool f[200005];

bool cmp(int x, int y)
{
    return x> y;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == 1) mn = a[i];
        else mn & a[i];
        if (maxn < a[i])
        {
            f[mi] = 0;
            maxn = a[i];
            mi = i;
            f[mi] = 1;
        }
    }
    if (m == n)
    {
        cout << mn << endl;
        return 0;
    }
    if (m == 1)
    {
        cout << maxn << endl;
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    maxn = a[1];
    for (int i = 2; i <= m; i++)
    {
        maxn = maxn & a[i];
    }
    cout << maxn << endl;
    return 0;
}
/*
rp++
9:19
?hyw
9:21
I find that my title is wrong,it's "and" instead of "ans"
too close to mo ai
9:22
emm...DP?
think
a & a = a so we can deal these at first
then try :
int maxn
for (mei ju mei you yong guo de shu)
{
    maxn = max(last & a[i])
}
last = maxn
end
emm
a & a = a can give some youhua but it's so small
and I think it's wrong
let me have a try
9:30
wait
2^30?
2^30 = 1073741824
INT_MAX = 2147483647
i had better to long long
9:33
no long long
9:46
ok
why it's -1e9? why maxn don't have change?
9:53
ok I solve the bug
but i can't understand
why use the ts to put last & a[i] is ok but use last & a[i] without ts is wrong?
9:55
it's wrong
9:56
i deal the bug
10:00
wrong again
I don't want to deal
I'm so tired
*/
