#include <bits/stdc++.h>
using namespace std;
string c1_ , s1_ , c2_ , s2_;

void check(string c1 , string s1 , string c2 , string s2)
{
    bool a = false , b = false , c = false;
    if (c1 == c2)
    {
        cout << "1";
        a = true;
    }
    else
    {
        cout << "0";
    }
    string p1 , p2;
    p1 += s1[0];
    p1 += s1[1];
    p2 += s2[0];
    p2 += s2[1];
    if (p1 == p2 && a)
    {
        cout << "1";
        b = true;
    }
    else
    {
        cout << "0";
    }
    char z1 , z2;
    z1 = s1[2];
    z2 = s2[2];
    if (((z1 >= 'A' && z1 <= 'C' && z2 >= 'A' && z2 <= 'C') || (z1 >= 'D' && z1 <= 'E' && z2 >= 'D' && z2 <= 'E')) && a && b)
    {
        cout << "1";
        c = true;
    }
    else
    {
        cout << "0";
    }
    if (((int(z1) + 1 == int(z2)) || (int(z1) == int(z2) + 1)) && !((z1 == 'D' && z2 == 'C') || (z2 == 'D' && z1 == 'C')) && a && b && c)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
}

int main()

{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    cin >> c1_ >> s1_ >> c2_ >> s2_;
    check(c1_ , s1_ , c2_ , s2_);
    return 0;
}
