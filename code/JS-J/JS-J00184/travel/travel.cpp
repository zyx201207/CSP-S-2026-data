#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool bl1,bl2,bl3,bl4;
    string s1,s2,s3,s4;
    cin >> s1 >> s2 >> s3 >> s4;
    if(s1 == s3)
    {
        cout << 1;
        bl1 = true;
    }
    else cout << 0;
    if(bl1 == true && s2[0] == s4[0] && s2[1] == s4[1])
    {
        cout << 1;
        bl2 = true;
    }
    else cout << 0;
    if(bl2 == true)
    {
        if(char(s2[2]) >= 'A' && char(s2[2]) <= 'C' && char(s4[2]) >= 'A' && char(s4[2]) <= 'C')
        {
            cout << 1;
            bl3 = true;
        }
        else if(char(s2[2]) >= 'D' && char(s4[2]) <= 'E' && char(s4[2]) >= 'D' && char(s4[2]) <= 'E')
        {
            cout << 1;
            bl3 = true;
        }
        else cout << 0;
    }
    else cout << 0;
    if(bl3 == true && abs(char(s2[2]) - char(s4[2])) == 1) cout << 1;
    else cout << 0;
    return 0;
}
