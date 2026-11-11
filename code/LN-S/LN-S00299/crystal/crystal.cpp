#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, arr[N];
bool equal_pd = true, all_equal = true;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> arr[1];
    if (n == 1) {
        cout << 0;
        return 0;
    }
    cin >> arr[2];
    if (arr[2] != arr[1]) all_equal = false;
    long long cha = arr[2] - arr[1];
    for (int i = 3; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] != arr[1]) all_equal = false;
    }
    if (all_equal == true) {
        cout << n;
    } else {
        sort(arr + 1, arr + n + 1);
        long long ans = 0;
        for (int i = 2; i <= n; i++) {
            long long sum = m, pos = i, t = 0;
            while (sum >= arr[i] - arr[pos] && pos >= 1) {
                pos--;
                t++;
                sum -= arr[i] - arr[pos];
            }
            ans = max(ans, t);
        }
        cout << ans + 1;
    }
    return 0;
}
