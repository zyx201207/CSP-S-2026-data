#include <bits/stdc++.h>
using namespace std;
int a[500005];
int n, m;

// oh no, i can't work out any problem, i will down 555!

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    bool f = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] != i) {
            f = false;
        }
    }

    int sum = m;
    int ans = 1;
    if (f == true) {
        for (int i = n - 1; i >= 1; i--) {
            if (sum - (a[n] - a[i]) >= 0) {
                ans++;
                sum -= (a[n] - a[i]);
            } else {
                break; // sum is gone
            }
        }
        cout << ans << "\n";
        return 0;
    }

    for (int i = n - 1; i >= 1; i--) {
        if (sum - (a[n] - a[i]) >= 0) {
            ans++;
            sum -= (a[n] - a[i]);
        } else {
            cout << ans << "\n";
            return 0;
        }

    }



    return 0;
}
