#include <bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;

int get(char a) {
    if (a == 'F' || a == 'D')
        return 2;
    else
        return 1;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
        cout << "1";
    else
        cout << "0";

    if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1])
        cout << "1";
    else
        cout << "0";

    if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && get(s1[2]) == get(s2[2]))
        cout << "1";
    else
        cout << "0";

    if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && get(s1[2]) == get(s2[2]) && abs ((int) s1[2] - (int) s2[2]) == 1)
        cout << "1";
    else
        cout << "0";
}

