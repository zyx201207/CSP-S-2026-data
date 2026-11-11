#include <iostream>
#include <cstdio>
using namespace std;

int n;
int ad[100010];
char ac[100010];
string s;
long long num, ans;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    int num = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> ad[i] >> ac[i];
        for (int j = 1; j <= ad[i]; ++j) s[++num] = ac[i];
    }

    for (int i = 1; i <= num / 2; ++i) if (s[i] != s[num - i + 1]) ++ans;

    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
