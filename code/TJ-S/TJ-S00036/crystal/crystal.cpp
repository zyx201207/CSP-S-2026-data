#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n, m, a[500005], qzh[500005], ans = 0;
long long qjh(long long l, long long r)
{
    return qzh[r]-qzh[l-1];
}
void erfen(long long i)
{
    long long l = 1, r = i;
    while (l < r)
    {
        long long mid = (l+r)/2;
        if (a[i]*(i-mid+1)-qjh(mid, i) <= m)
        {
            r = mid;
        }
        else
        {
            l = mid+1;
        }
    }
    ans = max(ans, i-l+1);
    return ;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (long long i = 1; i <= n; i++)
    {
        qzh[i] = qzh[i-1]+a[i];
        erfen(i);
    }
    cout << ans;
    return 0;
}
