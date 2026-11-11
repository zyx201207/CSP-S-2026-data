#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200010];
bool b[200010][40], v[200010];
int c[40];
int ans;
void ch(int i, int num, int now)
{
    if (num == 0) return;
    b[i][now] = ((num % 2) == 1);
    c[now]++;
    ch(i, num / 2, now + 1);
    return;
}
void solve2(int num)
{
    if (num < 0) return;
    int maxn = 0;
    int flag = 0;
    for (int i = num; i >= 0; i--)
    {
        if (c[i] >= m)
        {
            int sum = 0;
            for (int j = 1; j <= n; j++)
            {
                if (b[j][i] && v[j]) sum++;
            }
            if (sum >= m)
            {
                maxn = i;
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1) ans += pow(2, maxn);
    for (int i = 1; i <= n; i++)
    {
        if (b[i][maxn] != 1 || v[i] != 1) v[i] = 0;
    }
    solve2(maxn - 1);
    return;
}
void solve()
{
    int maxn;
    for (int i = 31; i >= 0; i--)
    {
        if (c[i] >= m)
        {
            maxn = i;
            break;
        }
    }
    ans += pow(2, maxn);
    for (int i = 1; i <= n; i++)
    {
        if (b[i][maxn]) v[i] = 1;
    }
    solve2(maxn - 1);
    return;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ch(i, a[i], 0);
    }
    solve();
    cout << ans;
    return 0;
}
