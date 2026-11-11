#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct P {
    int a;
    char c;
} p[200007], pd[200007];
int n;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> p[i].a >> p[i].c;
        pd[i].a = p[i].a, pd[i].c = p[i].c;
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }
    reverse(pd, pd + n);

    long long ans = 0;
    int ll = 0, ld = 0;

    while (ll < n && ld < n) {
        int k = min(p[ll].a, pd[ld].a);
        if (p[ll].c != pd[ld].c) ans += k;
        p[ll].a -= k, pd[ld].a -= k;

        ll += (p[ll].a <= 0), ld += (pd[ld].a <= 0);
    }
    cout << ans / 2;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
