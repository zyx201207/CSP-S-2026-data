#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int n;
struct Info {
    int a;
    char c;
} s[N + 10];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].a >> s[i].c;
    }
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    long long ans = 0;
    long long num1 = s[1].a, num2 = s[n].a;
    char c1 = s[1].c, c2 = s[n].c;
    for (int i = 1, j = n; i < j; ) {
        if (num1 < num2) {
            ans += (c1 != c2) * num1;
            num2 -= num1, num1 = 0;
            num1 = s[++i].a, c1 = s[i].c;
        } else if (num1 == num2) {
            ans += (c1 != c2) * num1;
            num1 = 0, num2 = 0;
            num1 = s[++i].a, c1 = s[i].c;
            num2 = s[--j].a, c2 = s[j].c;
        } else {
            ans += (c1 != c2) * num2;
            num1 -= num2, num2 = 0;
            num2 = s[--j].a, c2 = s[j].c;
        }
    }
    cout << ans << '\n';
    return 0;
}
