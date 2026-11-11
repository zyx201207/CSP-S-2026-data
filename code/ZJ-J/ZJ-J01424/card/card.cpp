#include<bits/stdc++.h>
using namespace std;

int n, m, a[500005], ans[300005];
deque<int> p;
bool has[300005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        p.clear();
        for(int j = i; j <= n; j++)
        {
            if(!has[a[j]])
            {
                p.push_back(a[j]);
                has[a[j]] = true;
            }
            else
            {
                while(!p.empty() && p.back() != a[j])
                {
                    has[p.back()] = false;
                    p.pop_back();
                }
            }
        }
        for(int j = 1; j <= m; j++)
        {
            if(has[j])
            {
                ans[j]++;
            }
            has[j] = false;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout << ans[i] << " \n"[i == m];
    }
    return 0;
}