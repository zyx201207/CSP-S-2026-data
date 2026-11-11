#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long n, m, a[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);

    long long ans = 0;
    for(int i = n; i >= 1; i--)
    {
        if(i <= ans) break;
        long long sum = 1, cnt = 0;
        for(int j = i - 1; j >= 1; j--)
        {
            int cost = a[i] - a[j];
            if(cnt + cost > m) break;
            cnt += cost;
            sum++;
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}
