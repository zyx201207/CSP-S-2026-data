#include <cstdio>
#define max(a, b) (((a) > (b)) ? (a) : (b))
int c, t;
long long read()
{
    char ch = getchar();
    while(ch > '9' || ch < '0') ch = getchar();
    long long num = 0;
    while(ch >= '0' && ch <= '9')
    {
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    return num;
}
namespace task01_10
{
    long long x[5010];
    long long dp[5010];
    int best[5010];
    void solve()
    {
        int n;
        long long d;
        scanf("%d %lld", &n, &d);
        for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
        long long cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j <= n; j++) dp[j] = best[j] = 0;
            dp[i] = 1;
            int bt = i, lt = i;
            long long sum = 1;
            for(int j = i + 1; j <= n; j++)
            {
                while(x[j] - x[bt] > d)
                {
                    sum -= dp[bt];
                    bt++;
                }
                if(bt == j) break;
                best[j] = best[bt] + 1;
                while(best[lt] <= best[bt])
                {
                    lt++;
                    sum += dp[lt];
                }
                sum -= dp[lt];
                lt--;
                dp[j] = sum;
                if(sum == 2) cnt++;
            }
        }
        printf("%lld\n", cnt);
    }
}
namespace task11_12
{
    long long x[2000010];
    void solve()
    {
        int n;
        long long d;
        n = read();
        d = read();
        for(int i = 1; i <= n; i++) x[i] = read();
        if(n == 1)
        {
            puts("0");
            return ;
        }
        long long diff = (x[2] - x[1]);
        if(diff < 0) diff *= -1;
        if(d < 2 * diff)
        {
            puts("0");
            return ;
        }
        printf("%lld\n", max(0, n + 1 - 2 * (d / diff)));
    }
}
namespace pianzi
{
    long long x[2000010];
    void solve()
    {
        int n;
        n = read();
        for(int i = 1; i <= n; i++) x[i] = read();
        puts("0");
    }
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d %d", &c, &t);
    while(t--)
    {
        if(1 <= c && c <= 10) task01_10::solve();
        else if(11 <= c && c <= 12) task11_12::solve();
        else pianzi::solve();
    }
    return 0;
}
// Finish at 17:30
