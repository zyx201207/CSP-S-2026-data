#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long n, m;
long long a[N], p[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int max_ans;
    for (int i = n; i >= 1; i--) {
        int ans = 1, num = m;
        for (int j = i - 1; j >= 1; j--) {
            p[j] = a[i] - a[j];
            if (p[j] <= num) {
                num = num - p[j];
                ans++;
            } else {
                break;
            }
        }
        max_ans = max(max_ans, ans);
    }
    cout << max_ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
