#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
bool tcx, typ, tyc, xl;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        tcx = true;
    }
    if(tcx && s1[0] == s2[0] && s1[1] == s2[1])
    {
        typ = true;
    }
    if(typ && ((s1[2] >= 'D' && s2[2] >= 'D') || (s1[2] <= 'C' && s2[2] <= 'C')))
    {
        tyc = true;
    }
    if(tyc && (s1[2] == s2[2] + 1 || s1[2] == s2[2] - 1))
    {
        xl = true;
    }
    cout << tcx << typ << tyc << xl << endl;
    return 0;
}