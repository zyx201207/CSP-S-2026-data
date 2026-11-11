#include <cstdio>
#include <cmath>

const int IH = 39;
const int maxn = 2e6 + IH;
const int inf = 0x3f3f3f3f;

int c, t, ans = 0;
long long n, d;
long long x[maxn + IH], kase[maxn + IH], diff[maxn + IH][maxn + IH];

void __init(void)
{
    for (int i = 0 ; i <= n; i++) {
        kase[i] = 0;
    }
}

void migrate(int from, int go, int length)
{
    if (from == go) {
        kase[length]++;
        return;
    }
    for (int i = from + 1; i <= go; i++) {
        if (x[i] - x[from] > d) {
            break;
        }
        migrate(i, go, length + 1);
    }
}

int main(void)
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    scanf("%d %d", &c, &t);
    while (t--) {
        ans = 0;
        scanf("%lld %lld", &n, &d);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &x[i]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                __init();
                migrate(i, j, 0);
                for (int k = 0; k <= n; k++) {
                    if (kase[k] != 0) {
                        if (kase[k] == 2) {
                            ans++;
                        }
                        break;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }

}
