#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N];
long long len;
string str;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    int maxn = -1;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> a[i] >> c;
        len += a[i];
        maxn = max(maxn, a[i]);
        for (int j = 1; j <= a[i]; j++) {
            str += c;
        }
    }
    if (n <= 2000 || maxn <= 500) {
        string left, right;
        if (len % 2 == 1) {
            for (int i = 0; i < (len / 2) + 1; i++) {
                left += str[i];
            }
            for (int i = (len / 2) + 1; i < len; i++) {
                right += str[i];
            }
        }
        else {
            for (int i = 0; i < len / 2; i++) {
                left += str[i];
            }
            for (int i = len / 2; i < len; i++) {
                right += str[i];
            }
        }
        long long cnt = 0;
        long long cdk = len / 2;
        for (int i = 0; i < cdk; i++) {
            if (left[i] != right[i]) {
                cnt++;
            }
        }
        cout << cnt;
    }
    return 0;
}
