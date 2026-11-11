#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long ans = 0;
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    int x = 1, y = n, left = a[1], last = 1;
    while (x < y)
    {
        int flag = 1;
        if (b[x] == b[y]) flag = 0;
        if (last == x)
        {
            if (left > a[y])
            {
                left -= a[y];
                ans += (a[y] * flag);
                y--;
            }
            else if (left == a[y])
            {
                left = a[x + 1];
                ans += (a[y] * flag);
                last = x + 1;
                x++;
                y--;
            }
            else{
                ans += (left * flag);
                left = a[y] - left;
                last = y;
                x++;
            }
        }
        else{
            if (left > a[x])
            {
                left -= a[x];
                ans += (a[x] * flag);
                x++;
            }
            else if (left == a[x])
            {
                left = a[x + 1];
                last = x + 1;
                ans += (a[x] * flag);
                x++;
                y--;
            }
            else{
                ans += (left * flag);
                left = a[x] - left;
                last = x;
                y--;
            }
        }
    }
    cout << ans;
    return 0;
}
