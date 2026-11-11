#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m, a[500050], ans[500050];
vector<int> b;
int check(int x)
{
    for (int i = 0; i < b.size(); i++) if (b[i] == x) return i;
    return -1;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        // cout << "round: " << i << endl;
        for (int j = i; j <= n; j++)
        {
            int findx = check(a[j]);
            // cout << "Now is: " << j << endl;
            if (findx == -1) b.push_back(a[j]);
            else
            {
                 for (int k = findx; k <= b.size(); k++) b.pop_back();
                 b.push_back(a[j]);
            }
            // for (auto k : b) cout << k << " ";
            // cout << endl;
        }
        for (int j = 0; j < b.size(); j++) ans[b[j]]++;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}
