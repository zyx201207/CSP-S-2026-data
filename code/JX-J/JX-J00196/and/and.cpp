#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans;
vector<int> ok;
signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ok.push_back(x);
    }
    for (int i = 32; i >= 0; i--)
    {
        vector<int> x;
        for (int j = 0; j < ok.size(); j++)
        {
            if (ok[j] & (1<<i)) x.push_back(ok[j]);
        }
        if (x.size() >= m)
        {
            ans |= (1<<i);
            ok.clear();
            for (int j = 0; j < x.size(); j++) ok.push_back(x[j]);
        }
    }
    cout << ans;
    return 0;
}
