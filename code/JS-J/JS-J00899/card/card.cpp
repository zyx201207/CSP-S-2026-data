#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5,M = 5e3 + 5;
int n, m;
int a[N], ans[N], cnt[M];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    int minn = 1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        minn = min(minn, a[i] - a[i - 1]);
    }
    ans[a[n]]++;
    if (minn >= 0)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (a[j] != a[j + 1])
                {
                    ans[a[j]]++;
                    continue;
                }
                int step = 1;
                while (a[j] == a[j + i])
                {
                    j++;
                    step++;
                }
                if (step % 2 != 0) ans[a[j]]++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == a[i + 1]) continue;
            cout << ans[a[i]] << " ";
        }
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++) cnt[a[j]] = 0;
        queue<int> q;
        q.push(a[i]);
        cnt[a[i]]++;
        for (int j = i + 1; j <= n; j++)
        {
            if (cnt[a[j]] == 0)
            {
                q.push(a[j]);
                cnt[a[j]]++;
                continue;
            }
            int s = q.size();
            for (int k = 1; k <= s; k++)
            {
                int num = q.front();
                q.pop();
                if (num != a[j]) q.push(num);
                else
                {
                    while (k <= s)
                    {
                        cnt[q.front()]--;
                        q.pop();
                    }
                }
            }
        }
        for (int j = 1; j <= q.size(); j++)
        {
            ans[q.front()]++;
            q.pop();
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[a[i]] << " ";
    return 0;
}
