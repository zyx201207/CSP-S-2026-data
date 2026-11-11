#include <bits/stdc++.h>
using namespace std;

string func(string a, string b, string c, string d) {
    char ans[4];
    if (a != c) {
        return "0000";
    }
    ans[0] = '1';

    string col1, col2;
    col1 = b[0] + b[1];
    col2 = d[0] + d[1];
    if (col1 != col2) return "1000";

    int x = b[2] - 'A', y = d[2] - 'A';
    if (b[2] == 'D') x += 1;
    if (d[2] == 'D') y += 1;
    if (!((x >= 4 && y >= 4) || (x <= 2 && y <= 2))) return "1100";

    if (!(x - y == 1 or y - x == 1)) return "1110";

    return "1111";
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << func(a, b, c, d) << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
// ZZH39399