#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>

using namespace std;

int n, m, a[500005], ans, ls[500005], s[500005], cnt;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        s[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        ls[i] += a[i] - a[i - 1];
    }
    //for (int i = 0; i < n; i++)
    //{
    //    cout << ls[i] << " ";
    //}
    //cout << endl;
    int tot = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1]) s[tot]++;
        else tot++;
    }
    //for (int i = 0; i < n; i++)
    //{
    //    cout << s[i] << " ";
    //}
    tot = 0;
    for (int i = 0; i < n; i++)
    {
        tot += ls[i] * s[i];
        if (tot > m)
        {
            ans = i - 1;
            break;
        }
    }
    cout << ans;
    for (int i = 0; i < ans; i++)
    {
        a[i] = a[ans];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[ans]) cnt++;
    }
    //cout << cnt << endl;
    cnt += max(0, (a[n - 1] - tot) / ls[ans + 1]);
    cout << cnt;
    return 0;
}
