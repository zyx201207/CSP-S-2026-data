#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 200007;

int n, ans;
int a[N];
char c[N];

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    int i = 1, j = n;
    while (i <= j) {
 //       cout << i << " " << j << endl;
        if (c[i] == c[j]) {
            if (a[i] > a[j]) {
                a[i] -= a[j];
                j--;
            }
            else if (a[j] > a[i] ) {
                a[j] -= a[i];
                i++;
            }
            else if (a[i] == a[j]) {
                i++;
                j--;
            }
        }
        else {
            if (a[i] > a[j]) {
                ans += a[j];
                a[i] -= a[j];
                j--;
            }
            else if (a[j] > a[i] ) {
                ans += a[i];
                a[j] -= a[i];
                i++;
            }
            else if (a[i] == a[j])
            {
                ans += a[i];
                i++;
                j--;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

/*

aaaaccbbba
4 a
2 c
3 b
1 a



*/
