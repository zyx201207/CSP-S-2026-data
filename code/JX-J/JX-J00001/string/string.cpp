#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 1;
ll L, ans;
int n, a[N];
char c[N];
vector<char> S;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) {
        scanf("%d %c", &a[i], &c[i]);
        for (int j = 1;j <= a[i];j++)
            S.push_back(c[i]);
        L += a[i];
    }
    for (ll i = 0, j = L-1;i < j;i++, j--)
        if (S[i] != S[j])
            ans++;
    printf("%lld\n", ans);
}
