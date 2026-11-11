#include <bits/stdc++.h>
using namespace std;

const int inf = 2147483647;
int n, m, ans = 0;
vector<int> a;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int mx = 0, mi = inf, mxn = 0;
    int nd = inf;
    cin >> n >> m;
    a.assign(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for(int k = 30; k >= 0; k--)
        {
            if(a[i] & (1 << i))
            {
                mxn = max(mxn, k);
                break;
            }
        }
        nd &= a[i];
        mx = max(mx, a[i]);
    }
    if(m == 1)
    {
        cout << mx << endl;
        return 0;
    }
    if(m == n)
    {
        cout << nd << endl;
        return 0;
    }
    int ans = 0;
    vector<int> x(a);
    for(int i = mxn; i >= 0; i--)
    {
        int cnt = 0;
        vector<int> y(x);
        x.clear();
        for(auto v : y)
        {
            if(v & (1 << i))
            {
                cnt++;
                x.push_back(v);
            }
        }
        if(cnt < m)
        {
            x.clear();
            x = a;
            if(ans != 0)
                break;
        }
        else
        {
            ans += 1 << i;
        }
        if(x.size() < m)
            break;
    }
    cout << ans << endl;
    return 0;
}
