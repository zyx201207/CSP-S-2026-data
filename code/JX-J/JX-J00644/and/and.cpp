#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];

int main () {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {

        cin >> a[i];

    }

    sort(a + 1, a + n + 1);

    long long maxn = 0;

    for (int i = n; i >= m; i--) {

        int j = i - 1, t = m - 1;

        long long ans = a[i];

        while (t > 0 && j > 0) {

            if ((ans & a[j]) == 0) {

                j--;
                continue;

            }

            ans &= a[j];
            j--;
            t--;

        }

        if (t != 0) {

            ans = 0;

        }

        maxn = max(maxn, ans);

    }

    cout << maxn;


    return 0;
}
