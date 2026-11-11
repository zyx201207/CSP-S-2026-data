#include <bits/stdc++.h>
using namespace std;
int solve1 (string s) {
    int res = 0, n = s.size ();
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') res = res * 10 + (s[i] - '0');
    }
    return res;
}
int solve2 (string s) {
    int n = s.size ();
    return (s[n - 1] <= 'C');
}
int solve3 (string s) {
    int n = s.size ();
    return (s[n - 1] - 'A');
}
int main () {
    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);
    string car1, car2, seat1, seat2; cin >> car1 >> seat1 >> car2 >> seat2;
    if (car1 != car2) cout << "0000" << "\n";
    else {
        int A = solve1 (seat1), B = solve1 (seat2);
        if (A != B) cout << "1000" << "\n";
        else {
            int ch1 = solve2 (seat1), ch2 = solve2 (seat2);
            if (ch1 != ch2) cout << "1100" << "\n";
            else {
                int num1 = solve3 (seat1), num2 = solve3 (seat2);
                if (abs (num1 - num2) <= 1) cout << "1111" << "\n";
                else cout << "1110" << "\n";
            }
        }
    }
    return 0;
}
