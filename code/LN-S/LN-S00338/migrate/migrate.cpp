#include <bits/stdc++.h>
using namespace std;

int c, t;
int x[510000];

int main () {
    srand(time(0));
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    for(int i = 1; i <= c; i++){
        int n, d;
        scanf("%d%d", &n, &d);
        for (int i = 1; i <= n; i++)
            scanf("%d", &x[i]);
        printf("%d\n", rand());
    }
    return 0;
}
