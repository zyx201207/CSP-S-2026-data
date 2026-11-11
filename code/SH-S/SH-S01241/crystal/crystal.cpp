#include <bits/extc++.h>

using namespace std;

ifstream fin("crystal.in");
ofstream fout("crystal.out");

using iil = istream_iterator<long>;

const uint N = 5e5 + 5;

uint n, ans;
long m, cur, a[N];

int main() {
    fin >> n >> m, copy_n(iil(fin), n, a), sort(a, a + n, greater<long>());
    for (uint i = -1, j = 0; ++i < n; ans = max(ans, j - i), cur += (j - i - 1) * (a[i + 1] - a[i]))
        for (; j < n && cur + a[i] - a[j] <= m; cur += a[i] - a[j++]);
    fout << ans;
}