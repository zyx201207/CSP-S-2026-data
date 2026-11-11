#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool a,b,c,d;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) a = true;
    else a = false;
    if(s1[0] == s2[0] && s1[1] == s2[1]) b = true;
    else b = false;
    auto x = s1[2],y = s2[2];
    if(x == 'C' && y == 'D') c = false;
    else if(x == 'D' && y == 'C') c = false;
    else c = true;
    if(x == 'A' && y == 'B') d = true;
    else if(x == 'B' && y == 'A') d = true;
    else if(x == 'B' && y == 'C') d = true;
    else if(x == 'C' && y == 'B') d = true;
    else if(x == 'D' && y == 'F') d = true;
    else if(x == 'F' && y == 'D') d = true;
    else d = false;
    cout << a << endl << b << endl << c << endl << d;
    return 0;
}
