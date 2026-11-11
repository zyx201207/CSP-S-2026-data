#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool flag[4] = {};
    flag[0] = (c1 == c2);
    flag[1] = flag[0] && (s1[0] == s2[0]) && (s1[1] == s2[1]);
    char l[3] = {'A', 'B', 'C'};
    char r[2] = {'D', 'F'};
    bool f1 = false, f2 = false;
    for (int i = 0; i < 3; i++) {
		if (s1[2] == l[i]) f1 = true;
		if (s2[2] == l[i]) f2 = true;
    }
    flag[2] = flag[1] && (f1 == f2);
    char ch1 = s1[2], ch2 = s2[2];
    flag[3] = flag[2] &&
              ((ch1 == 'A' && ch2 == 'B') || (ch1 == 'B' && ch2 == 'A') ||
              (ch1 == 'B' && ch2 == 'C') || (ch1 == 'C' && ch2 == 'B') ||
              (ch1 == 'D' && ch2 == 'F') || (ch1 == 'F' && ch2 == 'D'));
    cout << flag[0] << flag[1] << flag[2] << flag[3];

    fclose(stdin);
    fclose(stdout);
    return 0;
}
