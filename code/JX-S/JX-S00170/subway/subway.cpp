#include <iostream>
#include <cstdio>
using namespace std;
long long read()
{
    long long sum = 0;
    int f = 1;
    char ch = getchar();
    if(ch < '0' || ch > '9')
    {
        f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        int x = ch - '0';
        sum = sum * 10 + x;
        ch = getchar();
    }
    return 1ll * f * sum;
}
const int MAXN = 500;
const int MAXM = 5e5 + 5;
int c, n, m, d, q;
int w[MAXM], a[505][MAXM], t[MAXM][505], sta[505];
//vector<int> edges[MAXM];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    c = read(), n = read(), m = read(), d = read(), q = read();
    for(int i = 1; i <= m; i++)
    {
        w[i] = read();
    }
    for(int i = i; i <= n; i++)
    {
        sta[i] = read();
        for(int j = 1; j <= sta[i]; j++)
        {
            a[i][j] = read(), t[a[i][j]][i] = read();
        }
    }
    while(q--)
    {
        int sx = read(), sy = read();
        cout << 0 << endl;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
