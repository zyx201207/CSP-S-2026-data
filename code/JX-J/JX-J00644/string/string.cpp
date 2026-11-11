#include<bits/stdc++.h>
using namespace std;

int n;

struct abc {

    int cnt;
    char c;

}k[100005];

int main () {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;

    for (int i = 1; i <= n; i++) {

        cin >> k[i].cnt >> k[i].c;

    }

    int l = 1, r = n;
    long long ans = 0;

    while (l <= r) {

        if (k[l].c != k[r].c) {

            if (k[l].cnt < k[r].cnt) {

                ans += k[l].cnt;
                k[r].cnt -= k[l].cnt;
                l++;

            }

            else if (k[l].cnt > k[r].cnt) {

                ans += k[r].cnt;
                k[l].cnt -= k[r].cnt;
                r--;

            }

            else {

                ans += k[l].cnt;
                l++, r--;

            }

        }

        else {

            if (k[l].cnt < k[r].cnt) {

                k[r].cnt -= k[l].cnt;
                l++;

            }

            else if (k[l].cnt > k[r].cnt) {

                k[l].cnt -= k[r].cnt;
                r--;

            }

            else {

                l++, r--;

            }

        }

    }

    cout << ans;

    return 0;
}
