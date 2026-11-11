#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long read()
{
    long long sum = 0;
    int f = 1;
    char ch = getchar();
    if(ch < '0' || ch > '9')
    {
        f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        int x = ch - '0';
        sum = sum * 10 + x;
        ch = getchar();
    }
    return 1ll * f * sum;
}
const int MAXN = 5e5 + 5;
long long n, m, a[MAXN], k = 1;
long long num[MAXN], sum[MAXN];
int res = 1;
int check(int s)
{
    int l = 1, r = s, ans = 0;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        long long x = num[s] * (s - mid + 1) - (sum[s] - sum[mid-1]);
        if(x > m)
            l = mid + 1;
        else if(x <= m)
            ans = mid, r = mid - 1;
    }
    return ans;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        num[i] = a[i] - a[1];
        sum[i] = sum[i - 1] + num[i];
        if(sum[i] <= m) k = i;
    }
    for(int i = 1; i <= n; i++)
    {
        int x = check(i);
        if(x == 0) continue;
        res = max(res, i - x + 1);
    }
    cout << res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
