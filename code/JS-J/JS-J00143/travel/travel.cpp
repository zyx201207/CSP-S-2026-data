#include <bits/stdc++.h>
using namespace std;

bool ische, ispai, ispaice, isxiang;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    char se1 = s1[2], se2 = s2[2];
    string tmp1 = "" + s1[0] + s1[1], tmp2 = "" + s2[0] + s2[1];
    s1 = tmp1;
    s2 = tmp2;
    bool tmpa = (se1 == 'A' || se1 == 'B' || se1 == 'C') && (se2 == 'A' || se2 == 'B' || se2 == 'C'), tmpb = (se1 == 'D' || se1 == 'F') && (se2 == 'D' || se2 == 'F');

    if(c1 == c2) ische = true;
    if(ische && s1 == s2) ispai = true;
    if(ispai && (tmpa || tmpb)) ispaice = true;
    if(ispaice && ((se1 == 'A' && se2 == 'B') || (se1 == 'B' && se2 == 'A') || (se1 == 'B' && se2 == 'C') || (se1 == 'C' && se2 == 'B') || (se1 == 'D' && se2 == 'F') || (se1 == 'F' && se2 == 'D'))) isxiang = true;

    cout << ische << ispai << ispaice << isxiang;


    return 0;
}
