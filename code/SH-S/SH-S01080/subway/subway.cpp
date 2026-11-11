#include<bits/stdc++.h>
using namespace std;
using itn = int;
using ll = int64_t;
#define endl '\n'
#define file "subway"
template<typename T> void read(T &d)
{
    T x = 0; char ch;
    do ch=getchar_unlocked(); while (isspace(ch));
    do x=x*10+ch-'0', ch=getchar_unlocked(); while (isdigit(ch));
    d = x;
}
template<typename T> void readneg(T &d)
{
    T x = 0; char ch; bool neg;
    do ch=getchar_unlocked(); while (isspace(ch));
    neg = ch == '-'; if (neg) ch = getchar();
    do x=x*10+ch-'0', ch=getchar_unlocked(); while (isdigit(ch));
    d = neg ? -x : x;
}
const int maxn = 505, maxm = 504422;
const ll inf = LLONG_MAX / 4;
int w[maxm];
ll dis[maxn][maxn];
vector<pair<int, int>> subs[maxm]; 
int main(void)
{
    #ifndef NO_FREOPEN
    (void)!freopen(file ".in", "r", stdin);
    (void)!freopen(file ".out", "w", stdout);
    #endif
    int c, n, m, d, q, i, j, k;
    read(c); read(n); read(m); read(d); read(q);
    for (i=1; i<=m; i++) read(w[i]);
    for (i=1; i<=n; i++)
    {
        cin >> k;
        for (j=0; j<k; j++)
        {
            int a, t; read(a); read(t);
            subs[a].push_back({i, t});
        }
    }
    for (i=1; i<=n; i++) fill(dis[i], dis[i]+n+1, inf), dis[i][i] = 0;
    for (i=1; i<=m; i++)
    {
        for (j=0; j<(int)subs[i].size(); j++)
        {
            for (k=j+1; k<(int)subs[i].size(); k++)
            {
                auto p1 = subs[i][j], p2 = subs[i][k];
                dis[p1.first][p2.first] = dis[p2.first][p1.first] = min(dis[p1.first][p2.first], (ll)(p1.second+p2.second));
            }
        }
    }
    for (k=1; k<=n; k++)
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--)
    {
        int x, y; read(x); read(y);
        ll ans = inf;
        for (auto p1 : subs[x])
            for (auto p2 : subs[y])
                ans = min(ans, p1.second+p2.second+dis[p1.first][p2.first]);
        cout << ans + w[x] + w[y] << endl;
    }
}
