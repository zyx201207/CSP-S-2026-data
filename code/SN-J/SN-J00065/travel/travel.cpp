#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int x[5];
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        x[0] = 1;
        if(s1[0] == s2[0] && s1[1] == s2[1])
        {
            x[1] = 1;
            if(s1[2] <= 'C' && s2[2] <= 'C')
            {
                x[2] = 1;
                if(s1[4] == 'A' && s1[4] == 'B') x[3] = 1;
                else if(s1[4] == 'B' && s1[4] == 'A') x[3] = 1;
                else if(s1[4] == 'B' && s1[4] == 'C') x[3] = 1;
                else if(s1[4] == 'C' && s1[4] == 'B') x[3] = 1;
                else if(s1[4] == 'D' && s1[4] == 'F') x[3] = 1;
                else if(s1[4] == 'F' && s1[4] == 'D') x[3] = 1;
                else x[3] = 0;
            }
            else if(s1[2] <= 'D' && s2[2] <= 'D')
            {

            }
            else
                x[2] = 0;
                x[3] = 0;
        }
        else
        {
            x[1] = 0;
            x[2] = 0;
            x[3] = 0;
        }
    }
    else
    {
        x[0] = 0;
        x[1] = 0;
        x[2] = 0;
        x[3] = 0;
    }
    for(int i = 0;i < 4;i++)
        cout << x[i];
    return 0;
}
