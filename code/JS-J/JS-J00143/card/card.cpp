#include <bits/stdc++.h>
using namespace std;

long long a[500005];
long long cnt[300005];
long long ans[500005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    long long n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<long long> dc;
    for(int x = 1; x <= n; x++)
    {
        for(int i = x; i <= n; i++)
        {
            dc.push_back(a[i]);
            cnt[a[i]]++;
            int idx;
            if(cnt[a[i]] > 1)
            {
                for(int j = 0; j < dc.size(); j++)
                {
                    if(dc[j] == a[i])
                    {
                        idx = j;
                        break;
                    }
                }
                for(int j = dc.size(); j > idx; j--)
                {
                    cnt[a[j]] = 0;
                    dc.pop_back();
                }
                dc.push_back(a[i]);
                cnt[a[i]] = 1;
            }

        }
        for(int i = 0; i < dc.size(); i++)
        {
            ans[dc[i]]++;
        }
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < dc.size(); i++)
        {
            dc.clear();
        }
    }

    for(int i = 1; i <= m; i++) cout << ans[i] << ' ';


    return 0;
}
