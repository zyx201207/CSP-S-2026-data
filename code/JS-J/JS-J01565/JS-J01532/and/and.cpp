#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, a[200005], sum = 0;
    cin >> n >> m;
    int dp[200005][2];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (m = 1)
    {
        for (int i = 1; i <= n; i++)
        {
            sum = std::max(sum, a[i]);
        }
        cout << sum;
        return 0;
    }
    if (m = n)
    {
        sum = a[1];
        for (int i = 2; i <= n; i++)
        {
            sum = sum and a[i];
        }
        cout << sum;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int x = a[i] and a[j];
            sum = max(x, sum);
        }
    }
    cout << sum;
    return 0;
}
