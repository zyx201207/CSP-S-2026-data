#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    bool a,b,c,d = true;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(s1[2] == s2[2])
    {
        d = false;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1] && d == true)
    {
        cout << 1;
        a = true;
    }
    else
    {
        cout << 0;
        a = false;
    }
    if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C' && s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
    {
        b = true;
    }
    else if(s1[2] == 'D' || s1[2] == 'F' && s2[2] == 'D' || s2[2] == 'F')
    {
        b = true;
    }
    else
    {
        b == false;
    }
    if(a == true && b == true && d == true)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D')
    {
        c = true;
    }
    else if(s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'A' || s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'B')
    {
        c = true;
    }
    else
    {
        c = false;
    }
    if(a == true && b == true && c == true)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    return 0;
}
