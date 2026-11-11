#include <cstdio>
using namespace std;

int t;
int n;

void inp() {
    int c;
    scanf("%d%d", &c, &t);
}

void work() {
    while (t -- ) {
        int x;
        scanf("%d%d", &n, &x);

        for (int i = 1; i <= n; i ++ )
            scanf("%d", &x);

        printf("%d\n", (n + 3) / 4);
    }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    inp();
    work();

    fclose(stdin);
    fclose(stdout);

    return 0;
}
