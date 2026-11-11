#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m;

long long a[500010];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    deque<int> q;
    q.push_back(a[n]);
    int i = n,sum = 0;
    while(i > 1 && sum + (q.front() - a[i - 1]) <= m)
    {
        q.push_back(a[i - 1]);
        i--;
        sum += (q.front() - a[i]);
    }
    long long ans = q.size();
    while(i > 1)
    {
        q.push_back(a[i - 1]);
        i--;
        sum += q.front() - q.back();
        while(sum > m)
        {
            int h = q.front();
            q.pop_front();
            sum -= (q.size()) * (h - q.front());
        }
        ans = max((long long)(q.size()),ans);
    }
    cout << ans << "\n";
    return 0;
}
