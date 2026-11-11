#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    string cnt = "";
    if (c1 == c2)
    {
        cnt += '1';
        if (s1[0] == s2[0] && s1[1] == s2[1])
        {
            cnt += '1';
            char h = s1[2],h1 = s2[2];
            if ((h == 'A' && h1 == 'B') || (h == 'A' && h1 == 'C') || (h == 'B' && h1 == 'C') || (h == 'B' && h1 == 'A') || (h == 'B' && h1 == 'C') || (h == 'C' && h1 == 'A') || (h == 'D' && h1 == 'F') || (h == 'F' && h1 == 'D'))
            {
                cnt += '1';
                if ((h == 'A' && h1 == 'B') || (h == 'B' && h1 == 'A') || (h == 'B' && h1 == 'C') || (h == 'C' && h1 == 'B') || (h == 'D' && h1 == 'F') || (h == 'F' && h1 == 'D'))
                {
                    cnt += '1';
                }
                else
                {
                    cnt += '0';
                }
            }
            else
            {
                cnt += "00";
            }
        }
        else
        {
            cnt += "000";
        }
    }
    else
    {
        cnt = "0000";
    }
    cout << cnt;
    return 0;
}
