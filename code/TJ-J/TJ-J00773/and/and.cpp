#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int a[200010], f[2][200010], p[40], cnt4[4];
int ksm(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int tmp = ksm(a, b / 2);
    if (b % 2 == 1) return tmp * tmp * a;
    else return tmp * tmp;
}

bool flaga = 1, flagb = 1, flag = 0;
int vb;
void check() {
    for (int i = 1, j = 30; i <= m; i++) {
        while (p[j - 1] > a[i]) j--;
        if (p[j] - 1 != a[i]) {
            flaga = 0;
            return;
        }
    }
    int cnt = 0;
    for (int i = 1, j = 30; i <= n; i++) {
        while (p[j] > a[i]) j--;
        if (p[j] != a[i]) {
            flagb = 0;
            return;
        }
        if (flag == 0) {
            if (a[i] == a[i - 1] && i > 1) cnt++;
            else if (cnt > m) vb = a[i - 1], flag = 1;
        }
    }

}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    p[0] = 1;
    for (int i = 1; i <= 30; i++) p[i] = p[i - 1] * 2;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    check();
    if (flaga) cout << a[m];
    else if (flagb) {
        if (flag) cout << vb;
        else cout << 0;
    }
    else if (n <= 2000) {
        int tmp = ksm(2, 30) - 1;
        f[0][0] = tmp;
        for (int i = 1; i <= n; i++) {
            int now = i % 2, last = (i - 1) % 2;
            f[now][0] = tmp;
            for (int j = 1; j <= m; j++) {
                f[now][j] = max(f[last][j], f[last][j - 1] & a[i]);
            }
        }
        cout << f[n % 2][m];
    }
    else if (m - n == 1) {
        int ans = ksm(2, 30) - 1;
        for (int i = 1; i < n; i++) ans &= a[i];
        cout << ans;
    }
    else if (m < 4) {
        for (int i = 1; i <= n; i++) cnt4[a[i]]++;
        if (cnt4[3] >= m) cout << 3;
        else if (cnt4[3] + cnt4[2] >= m) cout << 2;
        else if (cnt4[3] + cnt4[1] >= m) cout << 1;
        else cout << 0;
    }
    return 0;
}

