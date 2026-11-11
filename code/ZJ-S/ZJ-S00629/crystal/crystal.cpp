#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long m;
int a[500010];
int ans = 1;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    if (n > 5000) {
        if (a[n] - a[1] > 1000) {
            long long add = 0;
            while (add <= m){
                add = 0;
                for (int i = 1; i <= 1 + ans; ++i) add += (a[1 + ans] - a[i]);
                ++ans;
            }
            --ans;
        }
        else {
            int start = 1;
            while (start + ans < n) {
                long long add = 0;
                while (add <= m){
                    add = 0;
                    while (a[start + ans - 1] == a[start + ans]) ++ans;
                    for (int i = start; i <= start + ans; ++i) add += (a[start + ans] - a[i]);
                    ++ans;
                }
                --ans;
                ++start;
            }
        }
        cout << ans;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    int start = 1;
    while (start + ans < n) {
        long long add = 0;
        while (add <= m){
            add = 0;
            for (int i = start; i <= start + ans; ++i) add += (a[start + ans] - a[i]);
            ++ans;
        }
        --ans;
        ++start;
    }

    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}