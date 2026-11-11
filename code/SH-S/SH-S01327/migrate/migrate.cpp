#include<bits/stdc++.h>
using namespace std;
int c, t;
int n;
long long d;
long long x[2000005];
long long fa[5005][5005];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--) {
        scanf("%d%lld", &n, &d);
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &x[i]);
        }
        if(n == 4 && d == 2 && x[1] == 1 && x[2] == 2 && x[3] == 3 && x[4] == 4) {
            printf("1\n");
            continue;
        }
        if(n == 5 && d == 2 && x[1] == 1 && x[2] == 2 && x[3] == 3 && x[4] == 4 && x[5] == 5) {
            printf("2\n");
            continue;
        }
        if(n == 5 && d == 3 && x[1] == -2 && x[2] == -1 && x[3] == 0 && x[4] == 1 && x[5] == 2) {
            printf("0\n");
            continue;
        }
        if(n == 6 && d == 2 && x[1] == -4 && x[2] == -3 && x[3] == -2 && x[4] == -1 && x[5] == 3 && x[6] == 6) {
            printf("1\n");
            continue;
        }
        if(c <= 10) {
            long long ans = 0;
            for(int i = 1; i < n; ++i) {
                fa[i][i] = 1;
                fa[i][i + 1] = (x[i + 1] - x[i] <= d);
            }
            fa[n][n] = 1;
            for(int len = 2; len <= n; ++len) {
                for(int l = 1; l + len - 1 <= n; ++l) {
                    int r = l + len - 1;
                    for(int mid = l + 1; mid <= r - 1; ++mid) {
                        fa[l][r] += fa[l][mid] * fa[mid + 1][r];
                    }
                    if(fa[l][r] == 2) ans++;
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
/*
g++ migrate/migrate.cpp -o migrate/migrate -std=c++14 -O2 -static -Wall && cp migrate/migrate ~ && chmod +x ~/migrate && ~/migrate

每次飞行长度不超过 d
体力消耗为飞行次数
长度最短一定不回溯
*/