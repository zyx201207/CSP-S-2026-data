#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N];
char c[N];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i];
    }

    int l = 1;
    int r = n;
    int numl = a[1];
    int numr = a[n];
    long long ans = 0;

    while (l < r) {
        if (c[l] != c[r]) {
            ans += min(numl, numr);
        }
        if (numl > numr) {
            numl -= numr;
            --r;
            numr = a[r];
        } else if (numl < numr) {
            numr -= numl;
            ++l;
            numl = a[l];
        } else {
            ++l;
            --r;
            numl = a[l];
            numr = a[r];
        }
    }

    cout << ans;
    return 0;
}
