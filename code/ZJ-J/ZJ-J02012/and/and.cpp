#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 200010;

int a[MAXN], n, m, ans;
int cnt[2];
bool b[MAXN];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        b[i] = true;
    }
    ans = 0;
    for (int j=30; j>=0; j--) {
        cnt[0] = 0;
        cnt[1] = 0;
        for (int i=1; i<=n; i++) {
            if (!b[i]) continue;
            if (a[i]&(1<<j)) cnt[1] ++;
            else cnt[0]++;
        }
        if (cnt[1] >= m) {
            ans += (1<<j);
            for (int i=1; i<=n; i++) {
                if (!b[i]) continue;
                if (!(a[i]&(1<<j))) {
                    b[i] = false;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
