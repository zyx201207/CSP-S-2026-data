#include <bits/stdc++.h>
using namespace std;
int n, arr[200005];
char ch[200005];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i] >> ch[i];
    }
    int l = 1, r = n;
    long long ans = 0;
    while (l < r) {
        int numl = arr[l], numr = arr[r];
        // cout << arr[l] << " " << arr[r] << " ";
        if (ch[l] == ch[r]) {
            if (numl == numr) { l++, r--; }
            if (numl > numr) { arr[l] -= arr[r--]; }
            if (numl < numr) { arr[r] -= arr[l++]; }
        }
        else {
            if (numl == numr) {
                 // cout << numl << endl;
                l++, r--;
                ans += numl;
            }
            if (numl > numr) {
                // cout << numr << endl;
                arr[l] -= arr[r--];
                ans += numr;
            }
            if (numl < numr) {
                // cout << numl << endl;
                arr[r] -= arr[l++];
                ans += numl;
            }
        }
    }
    cout << ans;
    return 0;
}
