#include <iostream>
using namespace std;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        int a;
        string c;
        cin >> a >> c;
        for (int _ = 0; _ < a; _++) {
            s.append(c);
        }
        //s.append(c, a);
    }
    //cout << s << endl;
    long long ans = 0;
    for (int i = 0; i < s.size() / 2; i++) {
        int j = s.size() - i - 1;
        if (s[i] != s[j]) {
            ans++;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
