#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

long long a[MAXN], b[MAXN];
char c[MAXN], d[MAXN];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    long long z = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        z += a[i];
    }
    for (int i = n; i >= 1; i--) {
        b[n - i + 1] = a[i];
        d[n - i + 1] = c[i];
    }
    long long sum = 0;
    long long mid = z / 2;
    int h = 0;
    for (int i = 1; i <= n; i++) {
        h++;
        long long tmp = sum;
        sum += a[i];
        if (sum >= mid) {
            a[i] = mid - tmp;
            break;
        }
    }
    sum = 0;
    for (int i = 1; i <= n; i++) {
        long long tmp = sum;
        sum += b[i];
        if (sum >= mid) {
            b[i] = mid - tmp;
            break;
        }
    }
    int i = 1, j = 1;
    long long ans = 0;
    while (i <= h) {
        if (c[i] == d[j]) {
            if (a[i] > b[j]) {
                a[i] -= b[j];
                j++;
            } else if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                b[j] -= a[i];
                i++;
            }
            continue;
        }
        if (a[i] > b[j]) {
            ans += b[j];
            a[i] -= b[j];
            j++;
        } else if (a[i] == b[j]) {
            ans += a[i];
            i++;
            j++;
        } else {
            ans += a[i];
            b[j] -= a[i];
            i++;
        }
    }
    cout << ans;
    return 0;
}
