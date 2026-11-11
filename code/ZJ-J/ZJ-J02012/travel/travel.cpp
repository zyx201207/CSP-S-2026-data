#include<iostream>
#include<cstdio>
using namespace std;

string c1, c2, s1, s2;

bool check1() {
    if (c1 == c2) return true;
    return false;
}

bool check2() {
    if (s1[0] == s2[0] && s1[1] == s2[1]) return true;
    return false;
}

bool check3() {
    if (s1[2] <= 'C' && s2[2] <= 'C') return true;
    if (s1[2] >= 'D' && s2[2] >= 'D') return true;
    return false;
}

bool check4() {
    if (s1[2] == 'D' && s2[2] == 'F') return true;
    if (s1[2] == 'F' && s2[2] == 'D') return true;
    if (s1[2] == 'A' && s2[2] == 'B') return true;
    if (s1[2] == 'B' && s2[2] == 'A') return true;
    if (s1[2] == 'B' && s2[2] == 'C') return true;
    if (s1[2] == 'C' && s2[2] == 'B') return true;
    return false;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (!check1()) printf("0000");
    else  {
        if (!check2()) printf("1000");
        else {
            if (!check3()) printf("1100");
            else {
                if (!check4()) printf("1110");
                else printf("1111");
            }
        }
    }
    return 0;
}
