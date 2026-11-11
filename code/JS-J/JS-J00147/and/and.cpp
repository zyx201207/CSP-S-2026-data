#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int n, m, a[N + 10], num[35];
bool flag[N + 10];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 30; j++) {
            num[j] += ((a[i] >> j) & 1);
        }
    }
    int start = -1;
    for (int i = 30; i >= 0; i--) {
        if (num[i] >= m) {
            start = i;
            break;
        }
    }
    if (start == -1) {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        flag[i] = true;
    }
    int ans = 0, num = n;
    for (int i = start; i >= 0; i--) {
        stack<int> sta;
        for (int j = 1; j <= n; j++) {
            if (flag[j]) {
                if (!((a[j] >> i) & 1)) {
                    flag[j] = false;
                    num--;
                    sta.push(j);
                }
            }
        }
        if (num < m) {
            while (!sta.empty()) {
                flag[sta.top()] = true;
                sta.pop();
                num++;
            }
        } else {
            ans += (1 << i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
