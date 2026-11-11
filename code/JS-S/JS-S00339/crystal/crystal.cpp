#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, num[N], flag = 1, sum = 0, ans = 0;
long long m;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        sum += num[i];
    }
    sort(num + 1, num + n + 1);
    int l = 1, r = n, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (num[mid] - sum / n >= 0)
        {
            flag = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    while (num[flag + 1] == num[flag])
    {
        flag++;
    }
    for (int i = flag; i >= 1; i--)
    {
        if (num[flag] - num[i] > m)
        {
            break;
        }
        else
        {
            m -= num[flag] - num[i];
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
