#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define ll long long
int n;
pair<ll, char> a[200005];
int ans[128];
void add(string x) {
    int p = 0;
    for (int i = x.length() - 1; i >= 0; --i) {
        ans[++p] += x[i] - 48;
        int t = p;
        while (ans[t] >= 10) {
            ans[t + 1] += ans[t] / 10;
            ans[t] %= 10;
            ++t;
        }
    }
}
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    for (int i = 0; i < 127; ++i)
        ans[i] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i].first);
        cin >> a[i].second;
    }
    for (int i = 1, j = n; i < j && i <= n && j >= 1; ) {
        if (a[i].first > a[j].first) {
            if (a[i].second != a[j].second) {
                add(to_string(a[j].first));
            }
            a[i].first -= a[j].first;
            --j;
        } else if (a[i].first < a[j].first) {
            if (a[i].second != a[j].second) {
                add(to_string(a[i].first));

            }
            a[j].first -= a[i].first;
            ++i;
        } else {
            if (a[i].second != a[j].second) {
                add(to_string(a[i].first));

            }
            ++i;
            --j;
        }
    }
    int l = 127;
    while (ans[l] == 0 && l > 1) {
        --l;
    }
    for (int i = l; i >= 1; --i) {
        printf("%d", ans[i]);
    }

    printf("\n");
    return 0;
}
