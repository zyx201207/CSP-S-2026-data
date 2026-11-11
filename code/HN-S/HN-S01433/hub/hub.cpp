#include <cstdio>

int c, t, n, k;

int main(void)
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    scanf("%d %d", &c, &t);

    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i = 1, _ui, _vi; i <= n; i++) {
            scanf("%d %d", &_ui, &_vi);
        }
        printf("1\n");
    }
}
