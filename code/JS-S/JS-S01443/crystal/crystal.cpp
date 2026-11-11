#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e5 + 5;

long long arr[N];
long long n, m;
long long ans;

bool check(long long k)
{
    long long res = 0;
    for (long long i = 1; i <= n; ++i)
    {
        if (i <= k)
        {
            res += (i - 1) * (arr[i] - arr[i - 1]);
        } else
        {
            res = res - (arr[i - 1] - arr[i - k]) + (arr[i] - arr[i - 1]) * (k - 1);
        }

        if (i >= k && res <= m) return true;
    } return false;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for (long long i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 1);

    long long L = 1, R = n;
    while (L <= R)
    {
        long long M = L + R >> 1;
        if (check(M))
        {
            ans = M;
            L = M + 1;
        } else R = M - 1;
    }

    cout << ans << endl;

    return 0;
}