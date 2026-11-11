#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];
long long t[500005];

bool f[500005];

int main () {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;

    int maxn = 0;

    for (int i = 1; i <= n; i++) {

        cin >> a[i];
        t[a[i]]++;
        f[a[i]] = 1;

        maxn = max(a[i], maxn);

    }

    if (a[1] % 2 == 0) a[1]++;

    t[a[n]] = n;

    for (int i = 1; i <= maxn; i++) {

        if (f[i]) {

            cout << t[i] << ' ';

        }

    }

    return 0;
}
