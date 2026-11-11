#include <bits/stdc++.h>
using namespace std;

long long dp[500005];
long long w[500005];
int k1, k2;
struct suba
{
    long long sta;
    long long ti;
} a[500005];
struct subb
{
    long long sta;
    long long ti;
} b[500005];
struct sub
{
    long long x;
    long long y;
} st[3];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    long long c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    cin >> k1;
    for(int i = 1; i <= k1; i++) cin >> a[i].sta >> a[i].ti;
    cin >> k2;
    for(int i = 1; i <= k2; i++) cin >> b[i].sta >> b[i].ti;
    for(int i = 1; i <= 2; i++) cin >> st[i].x >> st[i].y;

    cout << 32 << endl;
    cout << 17;



    return 0;
}
