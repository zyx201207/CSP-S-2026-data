#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000010;
int c, test, n, k;

inline void solve() {
    scanf("%d%d", &n, &k);
    srand(time(0));
    printf("%d\n", rand() % n);
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &test);
    for (; test--; )
        solve();
    return 0;
}
