#include <bits/stdc++.h>
#define int long long
using namespace std;
ifstream fin("crystal.in");
ofstream fout("crystal.out");
const int N = 5e5 + 5;
int n, m, a[N], sum[N], ans;
signed main() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++) 
        fin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) 
        sum[i] = sum[i - 1] + a[i];
    for (int i = n, j = n; i >= 1; i--) {
        while (j && (i - (j - 1)) * a[i] - sum[i] + sum[(j - 1)] <= m) 
            j--;
        ans = max(ans, i - j);
    }
    fout << ans << '\n';
    return 0;
}

/*
背负着火影之名我不能输
luogu UID: 1449703

上善若水，人杰地灵

Rocketcar
*/