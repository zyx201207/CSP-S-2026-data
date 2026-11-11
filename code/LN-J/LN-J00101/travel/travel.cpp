#include <bits/stdc++.h>
using namespace std;

string a,b,s,n;
int flag[10];

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> s >> b >> n;
    if (a == b)
    {
        flag[1] = 1;
        if (s[0] + s[1] == n[0] + n[1])
        {
            flag[2] = 1;
            if ((n[2] <= 'C' && s[2] <= 'C') || (n[2] >= 'D' && n[2] >= 'D'))
            {
                flag[3] = 1;
                if ((n[2] == 'B' && (s[2] == 'A' || s[2] == 'C')) || (s[2] == 'B' && (n[2] == 'A' || n[2] == 'C')) || (s[2] == 'D' && n[2] == 'F') || (n[2] == 'D' && s[2] == 'F'))
                    flag[4] = 1;
            }
        }
     }
     for (int i = 1;i <= 4;i++)
        cout << flag[i];
}
