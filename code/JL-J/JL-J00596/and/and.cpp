#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long long solve() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long ans = 0;

    for (int k = 60; k >= 0; --k) {
        long long candidate = ans | (1LL << k);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if ((a[i] & candidate) == candidate) {
                count++;
            }
        }
        if (count >= m) {
            ans = candidate;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cout << solve() << endl;

    return 0;
}
