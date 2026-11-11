#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], cnt[300005];
vector<int> v, vv;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int s = v.size();
            for (int k = 0; k < s; k++)
            {
                if (v[k] == a[j])
                {
                    for (int p = 0; p < k; p++)
                    {
                        vv.push_back(v[p]);
                    }
                    v.clear();
                    break;
                }
            }
            int kk = vv.size();
            for (int q = 0; q < kk; q++)
            {
                v.push_back(vv[q]);
            }
            vv.clear();
            v.push_back(a[j]);
        }
        int f = v.size();
        for (int l = 0; l < f; l++)
        {
            cnt[v[l]]++;
        }
        v.clear();
    }
    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}
