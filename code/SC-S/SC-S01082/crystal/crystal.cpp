#include <algorithm>
#include <cstdio>

#define fi first
#define se second
#define pb push_back
#define mod(x) (x -= x >= Q ? Q : 0)

using namespace std;

typedef long long ll;

struct IO {
    IO () {
        freopen("crystal.in", "r", stdin);
        freopen("crystal.out", "w", stdout);
    }
    ~IO () {
        fclose(stdin);
        fclose(stdout);
    }
} io;

const int N = 5e5 + 5;

int n;
ll m, a[N], s[N];

bool chk (int x) {
    for (int i = 1; i <= n - x + 1; i++) {
        int l = i, r = i + x - 1;
        if (a[r] * x - (s[r] - s[l - 1]) <= m)
            return 1;
    }
    return 0;
}

int main () {
    // zyt
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (chk(mid))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d\n", l);
    return 0;
}