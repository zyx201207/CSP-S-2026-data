#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 5;
long long a[N], p[N];
int n, m;

int main()
{
    ifstream fin("crystal.in");
    ofstream fout("crystal.out");
    fin >> n >> m;
    for (int i = 1; i <= n; i++) fin >> a[i];
    sort(a + 1, a + 1 + n);
    partial_sum(a + 1, a + 1 + n, p + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r) >> 1;
            auto check = [=](int j) {
                return (i - j + 1) * a[i] - (p[i] - p[j - 1]) <= m;
            };
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }

    fout << ans << '\n';
    return 0;
}
