#include<bits/stdc++.h>
using namespace std;
long long w[500005], c, m, n, d, q;
long long vi[505][505];
struct Asd
{
    long long a, t;
};
vector <Asd> s[500005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    memset(vi, 0x3f, sizeof(vi));
    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++)
    {
        int isn;
        cin >> isn;
        for(int j = 1;j <= isn;j++)
        {
            long long a1, a2;
            cin >> a1 >> a2;
            s[a1].push_back({i, a2});
        }
    }
    for(int i = 1;i <= m;i++)
    {
        int a3 = s[i].size();
        for(int j = 0;j < a3;j++)
        {
            for(int k = 0;k < a3;k++)
            {
                if(k == j) continue;
                vi[s[i][j].a][s[i][k].a] = s[i][j].t + s[i][k].t;
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        vi[i][i] = 0;
    }
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                vi[i][j] = min(vi[i][j], vi[i][k] + vi[k][j]);
            }
        }
    }
    for(int i = 1;i <= q;i++)
    {
        int a4, a5;
        cin >> a4 >> a5;
        long long minn = 0x3f3f3f3f3f3f3f;
        int b1 = s[a4].size(), b2 = s[a5].size();
        for(int i = 0;i < b1;i++)
        {
            for(int j = 0;j < b2;j++)
            {
                minn = min(minn, vi[s[a4][i].a][s[a5][j].a] + s[a4][i].t + s[a5][j].t);
            }
        }
        cout << minn + w[a4] + w[a5] << endl;
    }
    return 0;
}
