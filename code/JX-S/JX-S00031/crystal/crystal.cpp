#include <bits/stdc++.h>

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int N;
    long long m;
    std:: cin >> N >> m;
    
    std:: vector<long long> arr(N + 1), pre(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        long long x;
        std:: cin >> x;
        arr[i] = x;
    }

    std:: sort(arr.begin() + 1, arr.end());
    for (int i = 1; i <= N; ++i)
    {
        pre[i] = pre[i - 1] + arr[i];
    }

    // a segment to a_i(has): i * a_i - pre[i - 1] + pre[j - 1] - j * a_i
    // notice: this is big to big

    int res = 0;
    for (int i = 1; i <= N; ++i)
    {
        int l = 1, r = i - 1, ans = i;
        long long cl = i * arr[i] - pre[i - 1];

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (cl + pre[mid - 1] - mid * arr[i] <= m)
            {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        res = std:: max(res, i - ans + 1);
    }

    std:: cout << res << '\n';
    return 0;
}