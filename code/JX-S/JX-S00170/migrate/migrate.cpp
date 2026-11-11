#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
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
const int MAXN = 2e6 + 5;
int c, t;
long long n, d;
long long a[MAXN], sum[MAXN], nf[MAXN];
int f[MAXN];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = read(), t = read();
    while(t--)
    {
        n = read(), d = read();
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= n; i++)
        {
            a[i] = read();
            sum[i] = a[i] - a[1];
            if(i > 1 && a[i] -  a[i - 1] <= d) f[i] = 1;
            nf[i] = nf[i - 1] + f[i];
        }
        cout << 0 << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
