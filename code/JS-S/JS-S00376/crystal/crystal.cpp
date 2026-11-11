#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], maxn, th = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long l = 1, r = 1;
    while(r < n)
    {
        r++;
        if(a[r - 1] != a[r]) th += (r - l) * (a[r] - a[r - 1]);
        while(th > m)
        {
            l++;
            th -= a[r] - a[l - 1];
        }
        maxn = max(maxn, r - l + 1);
    }
    cout << maxn;
    return 0;;
}
