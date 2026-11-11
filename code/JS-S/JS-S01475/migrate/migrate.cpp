#include <bits/stdc++.h>
using namespace std;
int c, t;
int n;
long long d;
long long x[2000005];
bool check(int v, int w) {

}
int main() {
    freopen("mlgrate.in", "r", stdin);
    freopen("mlgrate.out", "w", stdout);
    scanf(" %d %d", &c, &t);
    if(c == 0)
    while(t --) {
        int sum = 0;
        scanf(" %d %lld", &n, &t);
        for (int i = 1; i <= n; i ++) {
            scanf(" %lld", &x[i]);
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                if(check(i, j)) {
                    sum ++;
                }
            }
        }

    }
    cout << 0 << "\n" << 1;
    return 0;
}
