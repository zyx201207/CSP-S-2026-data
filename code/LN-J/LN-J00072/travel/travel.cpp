#include <bits/stdc++.h>

using namespace std;

int main () {
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    /*ios::sync_with_stdio(false);
    cin.tie(nullptr);*/

    string c1 , s1 , c2 , s2;
    cin >> c1 >> s1 >> c2 >> s2;

    if (c1 == c2) {
        cout << "1";
    } else {
        cout << "0000";
        return 0;
    }

    string a1 = "" , a2 = "";
    for (int i = 0; i < s1.size() - 1; i ++) a1 += s1[i];
    for (int i = 0; i < s2.size() - 1; i ++) a2 += s2[i];

    if (a1 == a2) {
        cout << "1";
    } else {
        cout << "000";
        return 0;
    }

    char n1 = s1[s1.size() - 1] , n2 = s2[s2.size() - 1];;
    int x = n1 - 64;
    int y = n2 - 64;

    if ((x <= 3 && y <= 3) || (x >= 4 && x <= 5 && y >= 4 && y <= 5)) {
        cout << "1";
    } else {
        cout << "00";
        return 0;
    }

    if (abs(x - y) == 1) {
        cout << "1";
    } else {
        cout << "0";
        return 0;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
