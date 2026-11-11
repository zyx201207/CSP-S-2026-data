#include <bits/stdc++.h>
using namespace std;

string s = "";
long long a[200005];
char b[200005];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    long long l = 0, r = n - 1;
    long long cnt = 0;


    while (l < r) {
        if (b[l] == b[r]) {
            if (a[l] < a[r]) {
                a[r] -= a[l];
                l += 1;
            }
            else if (a[l] > a[r]) {
                a[l] -= a[r];
                r -= 1;
            }
            else {
                a[l] = a[r] = 0;
                l += 1;
                r -= 1;
            }

        }
        else {
            if (a[l] < a[r]) {
                cnt += a[l];
                a[r] -= a[l];
                l += 1;
            }
            else if (a[l] > a[r]) {
                cnt += a[r];
                a[l] -= a[r];
                r -= 1;
            }
            else {
                cnt += a[l];
                a[l] = a[r] = 0;
                l += 1;
                r -= 1;
            }
        }
    }
    cout << cnt << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
// ZZH39399