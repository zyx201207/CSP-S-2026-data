#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[500005];
int cnt[300005];

vector<int> now;
unordered_map<int, int> pos;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        pos.clear();
        now.clear();
        for (int j = i; j <= n; j++)
        {
            if (pos.count(a[j]) == 0)
            {
                now.push_back(a[j]);
                pos[a[j]] = now.size();
            }
            else
            {
                for (int g = pos[a[j]]; g < now.size(); g++)
                {
                    now[g] = -1;
                }
            }
        }
        for (auto k : now)
        {
            if (k > 0)
                cnt[k]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    cout << '\n';
}