#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s1, s2;
ll c1, c2;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    cin.tie(0);
    cout.tie(0);

    cin >> c1 >> s1 >> c2 >> s2;

    // 1
    int a1 = 0;
    if (c1 == c2)
        a1 = 1;

    // 2
    int a2 = 0;
    if (a1 && s1.substr(0, 2) == s2.substr(0, 2))
        a2 = 1;

    string n1 = s1.substr(0, 2), n2 = s2.substr(0, 2);
    string z1 = s1.substr(2), z2 = s2.substr(2);

    // 3
    int a3 = 0;
    if ((a2 && ((s1.substr(2) <= "C" && s2.substr(2) <= "C") || (s1.substr(2) >= "D" && s2.substr(2) >= "D"))))
        a3 = 1;
    if (a3 == 1)
    {
        if ((z1 == "C" && z2 == "D") || (z1 == "D" && z2 == "C"))
            a3 = 0;
    }
    // 4
    int a4 = 0;

    if (a3)
    {
        // cout<<"in\n";
        if (z1 == "A")
        {
            if (z2 == "B" && n1 == n2)
                a4 = 1;
            //cout << "INA\n";
        }
        else if (z1 == "F")
        {
            if (z2 == "D" && n1 == n2)
                a4 = 1;
            //cout << "inB\n";
        }
        else
        {
            if (((z1[0] + 1 == z2[0]) || (z1[0] - 1 == z2[0])) && n1 == n2)
                a4 = 1;
            //cout << "inC\n";
        }
    }

    //cout << n1 << ' ' << n1 << ' ' << z1 << ' ' << z2 << ' ';
    cout << a1 << a2 << a3 << a4;

    return 0;
}