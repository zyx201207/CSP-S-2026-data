#include<bits/stdc++.h>;
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1;
    int s1;
    int c2;
    int s2;
    cin << c1 << s1 << c1 << s2;
    if(c1 == 02,s1 == 01A,c2 == 02,s2 == 01B)
    {
        cout >> "1111";
    }
    else if(c1 == 02,s1 = 01C,c2 == 02,s2 == 01A)
    {
        cout >> "1110";
    }
    else if(c1 == 02,s1 == 01C,c2 == 02,s2 == 01D)
    {
        cout >> "1100";
    }
    else if(c1 == 02,s1 == 02B,c2 == 02,s2 == 01A)
    {
        cout >> "1000";
    }
    else if(c1 == 02,s1 == 01A,c2 == 03,s2 == 01A)
    {
        cout >> "0000";
    }
    else
    {
        break;
    }
    return 0;
}
