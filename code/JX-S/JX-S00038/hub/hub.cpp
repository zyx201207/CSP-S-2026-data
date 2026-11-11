#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];

int main () {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {

        cin >> a[i];

    }


    sort(a + 1, a + n + 1);

    int maxn = 0;

    for (int i = n; i >= 1; i--) {

        int t = m, cnt = 1;

        for (int j = i - 1; j >= 1; j--) {

            if (a[j] != a[i]) {

                if (t >= (a[i] - a[j])) {

                    t-= (a[i] - a[j]);

                }

                else {

                    break;

                }

             }


             cnt++;

        }

        maxn = max(maxn, cnt);

    }

    cout << maxn;

    return 0;
}

