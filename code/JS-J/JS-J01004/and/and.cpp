#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a[200005], ans = 0, maxhb = 0;

int highbit(int x)
{
    int ret = 0;
    while (x)
    {
        ret = x & -x;
        x -= x & -x;
    }
    return ret;
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    while (n >= m)
    {
        sort(a, a + n, cmp);
        maxhb = highbit(a[m - 1]);
        int nxtn = 0;
        for (int i = 0; i < n && a[i] > maxhb; ++i, ++nxtn)
            a[i] -= maxhb;
        n = nxtn;
        ans |= maxhb;
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
