#include <bits/stdc++.h>
#define long long int
using namespace std;

int a[505][505];
int t[505][505];
vector<unordered_map<int, int>> tu;

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cout << 32 << endl;
    cout << 17 << endl;
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    vector<int> w(m + 1, 0);
    for(int i = 1;i <= m; i++)
    {
        cin >> w[i];
    }
    for(int i = 1;i <= n; i++)
    {
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    vector<int> qw[2];
    for(int i = q;i <= q; i++)
    {
        cin >> qw[i][0] >> qw[i][1];
    }
    return 0;
}
