#include <bits/stdc++.h>
using namespace std;

bool is_side(char a, char b) {
    if (a>='A' && a<='C' && b>='A' && b<='C') {return abs(a-b)==1;}
    return (a=='D' || a=='F' && b=='D' || b=='F');
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2, answ[10]={"0"};
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
        answ[0]="1"; else answ[0]="0";

    if (answ[0]=="1" && s1[0]==s2[0] && s1[1]==s2[1])
        answ[1]="1"; else answ[1]="0";

    if ((answ[0]=="1" && answ[1]=="1") && (s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') || (s1[2]=='D' || s1[2]=='F' && s2[2]=='D' || s2[2]=='F'))
        answ[2]="1"; else answ[2]="0";

    if ((answ[0]=="1" && answ[1]=="1" && answ[2]=="1") && is_side(s1[2], s2[2]))
        answ[3]="1"; else answ[3]="0";

    for (int i = 0; i < 4; i++) cout << answ[i];
    return 0;
}
