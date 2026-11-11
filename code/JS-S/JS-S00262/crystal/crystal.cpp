#include <bits/stdc++.h>
using namespace std;

long long a[500005];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + 1 + n);
    long long ans = 0;
    for(long long i = n; i >= 2; i--)
    {
        long long tmp = m;
        long long cnt = i - 1;
        while(tmp >= 0 && cnt >= 1)
        {
            //cout << "chuli:" << tmp << ' ' << a[i] << " - " << a[cnt] << " cnt: " << cnt << endl;
            tmp -= abs(a[i] - a[cnt--]);
            //cout << "chuli:" << tmp << ' ' << a[i] << " - " << a[cnt] << " cnt: " << cnt << endl;
            if(tmp < 0) break;
        }
        if(cnt == 0) ans = max(ans, i);
        else ans = max(ans, i - cnt - 1);
    }

    cout << ans;


    return 0;
}
