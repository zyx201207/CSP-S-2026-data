#include <bits/stdc++.h>
#define N 200005
#define M 1000000005
#define int long long
using namespace std;
int nn, leng, cnt, a[N];
char ii[M], cc;
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> nn;
    a[0] = 0;
    for (int i = 1; i <= nn; i++) {
        cin >> a[i] >> cc;
        leng += a[i];
        a[i] += a[i-1];
        for (int j = a[i-1] + 1; j <= a[i]; j++) ii[j] = cc;
    }
    int leng1 = leng / 2;
    for (int i = 1; i <= leng1; i++) if (ii[i] != ii[leng+1-i]) cnt++;
    cout << cnt << '\n';
    return 0;
}
