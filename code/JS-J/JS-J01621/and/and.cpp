#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); i ++ )
#define DF(i, a, b) for (int i = (a); i >= (b); i -- )
inline void chkmin(int& a, int b) { if (a > b) a = b; }
inline void chkmax(int& a, int b) { if (a < b) a = b; }

const int N = 200010;

int n, m;

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    vector<int> v(n);
    F(i, 0, n - 1) cin >> v[i];
    vector<int> tmp;
    DF(i, 30, 0)
    {
        int cnt = 0;
        for (auto ele : v) cnt += ele >> i & 1;
        if (cnt >= m)
        {
            for (auto ele : v) if (ele >> i & 1) tmp.push_back(ele);
            v = move(tmp);
        }
    }
    while (v.size() > m) v.pop_back();
    int res = (1LL << 60) - 1;
    for (auto i : v) res &= i;
    cout << res << "\n";
    return 0; 
}