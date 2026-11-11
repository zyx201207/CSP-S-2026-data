#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool a[7];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        a[1] = true;
    }
    if ((s1[0] == s2[0]) && (s1[1] == s2[1]))
    {
        if (a[1] == true)
            a[2] = true;
    }
    int p1 = s1[2] - 'A';
    int p2 = s2[2] - 'A';
    if (((p1 <= 2) && (p2 <= 2)) || ((p1 > 2) && (p2 > 2)))
    {
        if (a[1] == true)
            if (a[2] == true)
            {
                a[3] = true;
            }
    }
    int po = abs(s1[2] - s2[2]);
    if (po == 1)
    {
        if (a[1] == true)
            if (a[2] == true)
            {
                if (a[3] == true)
                {
                    a[4] = true;
                }
            }
    }
    for (int i = 1;i <= 4;i++)
    {
        if (a[i] == true){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    return 0;
}
