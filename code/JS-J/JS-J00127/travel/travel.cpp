#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2)
    {
        cout << "0000";
        return 0;
    }
    int r1 = (s1[0]-'0')*10 + s1[1]-'0';
    int r2 = (s2[0]-'0')*10 + s2[1]-'0';
    if(r1 != r2)
    {
        cout << "1000";
        return 0;
    }
    if((s1[2] <= 'C' && s2[2] >= 'D') || (s1[2] >= 'D' && s2[2] <= 'C'))
    {
        cout << "1100";
        return 0;
    }
    if(abs(s1[2]-s2[2]) != 1)
    {
        cout << "1110";
        return 0;
    }
    cout << "1111";
    return 0;
}
