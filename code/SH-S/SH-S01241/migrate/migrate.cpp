#include <bits/extc++.h>

using namespace std;

ifstream fin("migrate.in");
ofstream fout("migrate.out");

using iil = istream_iterator<long>;

const uint N = 2e6 + 5;

uint c, t, n, lwb[N], upb[N], cnt[N], dir[N], drr[N];
long d, x[N];
ulong ans;
queue<uint> cnd;

int main() {
    for (fin >> c >> t; t--; fout << ans << '\n') {
        fin >> n >> d, copy_n(iil(fin), n, x), ans = 0;
        for (uint i = -1; ++i < n; lwb[i] = cnd.size() ? cnd.front() : i, cnd.push(i))
            for (uint j; cnd.size() && x[j = cnd.front()] < x[i] - d; upb[j] = i - 1, cnd.pop());
        for (uint i; cnd.size(); i = cnd.front(), upb[i] = n - 1, cnd.pop());
        for (uint i = n, j; --i; j = upb[i], drr[i] = 1 + (j != i && lwb[j] == i) * drr[j]);
        for (uint i = -1, j; ++i < n; j = lwb[i], dir[i] = 1 + (j != i && upb[j] == i) * dir[j], i - j > 1 && (
            ans += lwb[j + 2] - lwb[j + 1] + 
            (lwb[j + 2] != lwb[j + 1]) * (
                (1 + (lwb[j + 1] == lwb[j]) * (dir[lwb[j]] - 1)) * 
                (1 + (upb[j + 1] == upb[j]) * (drr[upb[j]] - 1)) - 1
        + (lwb[j + 2] != lwb[j + 1]) * 
        (lwb[j + 2] - lwb[j + 1] - 1) * 
        ((upb[j + 1] == upb[j]) * (drr[upb[j]] - 1)))));
    }
}