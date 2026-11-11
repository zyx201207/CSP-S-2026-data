#include <iostream>
#include <vector>
#define int long long
#define endl "\n"
using namespace std;

vector<int> vv;
int cnt[12][12][12];
int mini[10][10];

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        vv.clear();
        int n, d;
        cin >> n >> d;
        if (c == 11 || c == 12)
        {
            for (int i = 0; i < n; i++)
            {
                int ai;
                cin >> ai;
                vv.push_back(ai);
            }
            if (vv[1] - vv[0] > d)
            {
                cout << 0 << endl;
            }
            else
            {
                int qnt = d / (vv[1] - vv[0]);
                if (qnt == 1) cout << 0 << endl;
                else cout << max(0ll, n - 2 * qnt + 1) << endl;
            }
            continue;
        }
        else
        {
			for (int i = 0; i <= n; i++)
			{
				for (int j = 0; j <= n; j++)
				{
					mini[i][j] = 0;
					for (int k = 0; k <= n; k++)
					{
						cnt[i][j][k] = 0;
					}
				}
			}
			for (int i = 0; i < n; i++)
            {
                int ai;
                cin >> ai;
                vv.push_back(ai);
            }
            vector<int> t;
            for (int i = 0; i < (1 << n); i++)
            {
				t.clear();
				for (int j = 0; j < n; j++)
				{
					if (i & (1 << j))
					{
						t.push_back(j);
					}
				}
				bool flg = true;
				for (int i = 1; i < (int)t.size(); i++)
				{
					if (vv[t[i]] - vv[t[i - 1]] > d)
					{
						flg = false;
						break;
					}
				}
				if (flg && t.size() > 1)
				{
					cnt[t.front()][t.back()][t.size()]++;
					if (mini[t.front()][t.back()] == 0) mini[t.front()][t.back()] = t.size();
					else mini[t.front()][t.back()] = min(mini[t.front()][t.back()], (int)t.size());
				}
			}
			int ans = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (cnt[i][j][mini[i][j]] == 2) ans++;
				}
			}
			cout << ans << endl;
        }
    }
    return 0;
}
