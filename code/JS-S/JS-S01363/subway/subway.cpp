#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const long long maxll = 1e18 + 5;
int ta, tt, tsiz, tsiz2;//temporary a, temporary...
int c;
int n, m, d, q, l;
ll ans;
int res;
char cl = 0;
int w[500005];

ll FL[505][505];//Floyd
vector<int> a[505], t[505];
struct CnctNode{
    int ni;
    int dis;
};
vector<CnctNode> Cnct[500005];
int Read()
{
    res = 0;
    while ( cl < '0' || cl > '9')
        cl = getchar();
    while (cl >= '0' && cl <= '9')
    {
        res = (res << 3) + (res << 1) + (cl ^ 48);
        cl = getchar();
    }
    return res;
}
void Floyd()
{
    for (int k = 1;k <= n; ++k)
        for (int i = 1;i <= n; ++i)
            for (int j = 1;j <= n; ++j)
                FL[i][j] = min(FL[i][j], FL[i][k] + FL[k][j]);
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = Read(), n = Read(), m = Read(), d = Read(), q = Read();
    //printf("%d %d %d %d %d\n", c, n, m, d, q);
    for (int i = 1;i <= m; ++i)
        w[i] = Read();
    for (int i = 1;i <= n; ++i)
    {
        l = Read();
        for (int j = 1;j <= l; ++j)
        {
            ta = Read(), tt = Read();
            a[i].push_back(ta), t[i].push_back(tt);
            Cnct[ta].push_back({i, tt});
        }
    }
    memset(FL, 0x3f, sizeof FL);
    for (int i = 1;i <= m; ++i)
    {
        tsiz = Cnct[i].size();
        for (int j = 0;j < tsiz; ++j)
            for (int k = 0;k < tsiz; ++k)
            {
                if (k == j) continue;
                FL[Cnct[i][j].ni][Cnct[i][k].ni] = min(FL[Cnct[i][j].ni][Cnct[i][k].ni], (ll)Cnct[i][j].dis + Cnct[i][k].dis);
            }
    }
    for (int i = 1;i <= n; ++i) FL[i][i] = 0;
    for (int i = 1;i <= n; ++i)
        for (int j = i + 1;j <= n; ++j)
            FL[i][j] = FL[j][i] = min(FL[i][j], FL[j][i]);
    /*for (int i = 1;i <= n; ++i)
        for (int j = 1;j <= n; ++j)
            printf("%d%c", FL[i][j], " \n"[j == n]);*/
    //Do Floyd
    Floyd();
    int xi, yi;
    while (q--)
    {
        xi = Read(), yi = Read();
        ans = maxll;
        tsiz = Cnct[xi].size(), tsiz2 = Cnct[yi].size();
        for (int i = 0;i < tsiz; ++i)
        {
            for (int j = 0;j < tsiz2; ++j)
                ans = min(ans, FL[Cnct[xi][i].ni][Cnct[yi][j].ni] + Cnct[xi][i].dis + Cnct[yi][j].dis/*down the stairs*/);
        }
        printf("%lld\n", ans + w[xi] + w[yi]);
    }
    return 0;
}
/*
problem subway

Are you joking? It seems like a simple Floyd
16:15 pass all the tests
*/
