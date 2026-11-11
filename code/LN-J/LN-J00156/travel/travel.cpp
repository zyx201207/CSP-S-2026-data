#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string c1, s1, c2, s2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    string d1 = s1[0] + "" + s1[1];
    string d2 = s2[0] + "" + s2[1];
    char m1 = s1[2];
    char m2 = s2[2];
    printf("%d", c1 == c2);
    printf("%d", c1 == c2 && d1 == d2);
    bool flag = (m1 == 'F' || m1 == 'D') && (m2 == 'F' || m2 == 'D') || (m1 == 'A' || m1 == 'B' || m1 == 'C') && (m2 == 'A' || m2 == 'B' || m2 == 'C');
    printf("%d", c1 == c2 && d1 == d2 && flag);
    printf("%d\n", c1 == c2 && d1 == d2 && flag && abs(m1 - m2) <= 1);
    return 0;
}
