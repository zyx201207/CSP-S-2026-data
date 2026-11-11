#include<bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2)
    {
        cout << "0000";
        return 0;
    }
    cout << 1;
    if((s1[0] - '0') * 10 + (s1[1] - '0') != (s2[0] - '0') * 10 + (s2[1] - '0'))
    {
        cout << "000";
        return 0;
    }
    cout << 1;
    if(s1[2] - 'A' <= 2 && s2[2] - 'A' <= 2 || s1[2] - 'A' > 2 && s2[2] - 'A' > 2)
        cout << 1;
    else
    {
        cout << 0 << 0;
        return 0;
    }
    if((s1[2] - 'A') - (s2[2] - 'A') == 1 || (s1[2] - 'A') - (s2[2] - 'A') == -1 || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D')
        cout << 1;
    else
        cout << 0;
    return 0;
}//ABCDF
