#include <bits/stdc++.h>
using namespace std;
struct p_info { int cx, pai; char at; } x1, x2;

int get_int() {
    int result = 0;
    char c1 = getchar(), c2 = getchar();
    if (c1 == '0') {
        result = c2 - '0';
    } else {
        result = (c1 - '0') * 10 + (c2 - '0');
    }
    return result;
}

int main() {
#ifndef PDEBUG
    auto _1 = freopen("travel.in", "r", stdin);
    auto _2 = freopen("travel.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c1 = get_int(); getchar();
    int s1 = get_int();
    char s1_1 = getchar();
    getchar();
    int c2 = get_int(); getchar();
    int s2 = get_int();
    char s2_1 = getchar();
    bool adj = (s1_1 >= 'A' && s1_1 <= 'C' && s2_1 >= 'A' && s2_1 <= 'C') || (s1_1 >= 'D' && s1_1 <= 'F' && s2_1 >= 'D' && s2_1 <= 'F');
    cout << (c1 == c2) << (c1 == c2 && s1 == s2) << (c1 == c2 && s1 == s2 && adj) << (c1 == c2 && s1 == s2 && adj && abs(s2_1 - s1_1)== 1);
}