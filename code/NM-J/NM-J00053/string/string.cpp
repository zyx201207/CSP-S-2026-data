#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
	cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a[i] >> c[i];
    }
    long long ans = 0;
    long long n_1 = n-1;
    for (int i = 0;i < n/2;i++) {
        for (int j = n_1;j >= n/2;j--){
            if (a[i] > a[j]){
                if (c[i] != c[j]) ans = ans + a[i] - a[j];
                a[i] -= a[j];
                a[j] = 0;
            }
            else if (a[i] < a[j]){
                if (c[i] != c[j]) ans = ans + a[j] - a[i];
                a[j] -= a[i];
                a[i] = 0;
            }
            else if (a[i] == a[j]){
                if (c[i] != c[j]) ans = ans + a[i];
                a[i] = 0;
                a[j] = 0;
            }
            
            if (a[j] == 0 && a[i] != 0) {n_1 -= 1;continue;}
            if (a[i] == 0) i+=1;
            break;
        }
    }
    cout << ans;
    return 0;
}
