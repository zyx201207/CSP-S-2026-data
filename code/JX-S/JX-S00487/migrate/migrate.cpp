#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2000005;

long long x[MAXN];
int minn, num;
int n;
long long d;

void (int c, int g, int stp) {
    while ()
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%lld", &n, &d);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", x[i]);
        }
        long long ans = 0;
        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v <= n; v++) {
                num = 0;
                bfs(u, v, 0);
                if (num == 2) ans++;
            }
        }
    }
    return 0;
}
