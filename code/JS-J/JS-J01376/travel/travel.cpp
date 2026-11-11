#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin >> s1 >> s2 >> s3 >> s4;
    if(s1 != s3)
    {
        cout << "0000";
        return 0;
    }
    cout << 1;
    int p1,p2;
    p1 = ((s2[0] - 48) * 10) + (s2[1] - 48);
    p2 = ((s4[0] - 48) * 10) + (s4[1] - 48);
    if(p1 != p2)
    {
        cout << "000";
        return 0;
    }
    cout << 1;
    char c1 = s2[2],c2 = s4[2];
    if(!(((c1 >= 'A' && c1 <= 'C') && (c2 >= 'A' && c2 <= 'C')) || ((c1 >= 'D' && c1 <= 'F') && (c2 >= 'D' && c2 <= 'F'))))
    {
        cout << "00";
        return 0;
    }
    cout << 1;
    if(!((c1 == 'D' && c2 == 'F') || (c1 == 'F' && c2 == 'D') || (c1 == 'A' && c2 == 'B')|| (c1 == 'B' && c2 == 'C') || (c1 == 'B' && c2 == 'A') || (c1 == 'C' && c2 == 'B')))
       {

           cout << 0;
           return 0;
       }
       cout << 1;
    return 0;
}
