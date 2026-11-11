#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
long long a[N], b[N];
long long n, m, t;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    int fA = 0;
    for(long long i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]) fA = 1;
    }
    if(fA == 0) {
        long long sum = 0;
        long long jian = a[2] - a[1];
        for(long long i = 1; i <= n; i++) {
            sum += i * jian;
            if(sum > m) {
                cout << i << endl;
                return 0;
            }
        }
        cout << n << endl;
        return 0;
    }
    sort(a + 1, a + n + 1);
    long long maxn = 0, maxn2 = LLONG_MIN;
    int f = 0;
    for(long long i = 1; i <= n; i++) {

        b[i] = b[i - 1] + a[i];
        if(f == 0) {
            if(a[i] * (i - 1) - b[i - 1] > m) {
                f = 1;
                
            }else {
                maxn++;
            }
        }
        if(f == 1) {
            for(long long j = maxn2; j <= i - maxn; j++) {
                if(a[i] * (i - j - 1) - (b[i - 1] - b[j]) <= m) {
                    maxn = i - j;
                    maxn2 = j;
                    //cout << maxn2 << " " << i << " " << j << endl;
                    break;
                }
            }
        }
    }
    cout << maxn << endl;
    return 0;
}