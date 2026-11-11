#include <bits/stdc++.h>
using namespace std;
bool check(string a,string b)
{
    if (a[2] == 'D' && b[2] == 'F')
    {
        return true;
    }
    if (a[2] == 'F' && b[2] == 'D')
    {
        return true;
    }
    if (a[2] != 'D' && b[2] != 'F' && a[2] != 'F' && b[2] != 'D')
    {
        return true;
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        cout << 1;
        if (s1[0] == s2[0] && s1[1] == s2[1])
        {
            cout << 1;
            if (check(s1,s2))
            {
                cout << 1;
                if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B'))
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }
            else
            {
                cout << 0;
                cout << 0;
            }
        }
        else
        {
            for (int i = 1;i <= 3;i++)
            {
                cout << 0;
            }
        }
    }
    else
    {
        for (int i = 1;i <= 4;i++)
        {
            cout << 0;
        }
    }
    return 0;
}
