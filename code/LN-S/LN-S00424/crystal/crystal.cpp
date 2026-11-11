#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n;
    unsigned long long m;
    cin >> n >> m;
    vector <long long> a(n);
    for (long long i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int maxc = 0;
    for (long long i = 1; i < n; i++) {
        long long chah = 0;
        int count = 0;
        for (long long j = i; j >= 0; j--) {
            chah += a[i] - a[j];
            count = count + 1;
            if (chah >= m) {
                if (count > maxc && chah == m) {
                    maxc = count;
                } else if ((count-1) > maxc) {
                    maxc = count - 1;
                }
                break;
            }
        }
    }
    cout << maxc;
    return 0;
}
