#include <bits/stdc++>h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int a1 = (c1 == c2) ? 1 : 0;
    string r1s = s1.su(0, 2);
    char se1 = s1[2];
    string r2s = s2.su(0, 2);
    char se2 = s2[2];
    int a2 = (a1 == 1 && r1s == r2s) ? 1 : 0;
    int side1 = 0;
    if (se1 == 'A' || se1 == 'B' || se1 == 'C')
    {
        si1 = 0;
    }
    else
    {
        si1 = 1;
    }
    int si2 = 0;
    if (se2 == 'A' || se2 == 'B' || se2 == 'C')
    {
        si2 = 0;
    } else {
        si2 = 1;
    }
    int a3 = (a2 == 1 && si1 == si2) ? 1 : 0;
    int a4 = 0;
    if (a3 == 1)
    {
        if (si1 == 0)
        {
            if ((se1 == 'A' && se2 == 'B') || (se1 == 'B' && se2 == 'A'))
            {
                a4 = 1;
            }
            else if ((se1 == 'B' && se2 == 'C') || (se1 == 'C' && se2 == 'B'))
            {
                a4 = 1;
            }
        }
        else
        {
            if ((se1 == 'D' && se2 == 'F') || (se1 == 'F' && se2 == 'D'))
            {
                a4 = 1;
            }
        }
    }
    cout << a1 << a2 << a3 << a4 << endl;
    return 0;
}
