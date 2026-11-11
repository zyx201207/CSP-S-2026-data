#include <iostream>
#define ll long long
using namespace std;
const int MAXN = 2e5+10;
ll n, cnt;
char chr;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    string s = "";
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> cnt >> chr;
        for (; cnt > 0; cnt--) s += chr;
    }
    int j = (int) s.size() -1;
    for (int i = 0; i < (int) s.size() / 2; i++) {
        if (s[j] != s[i]) ans++;
        j--;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
