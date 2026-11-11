#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a;
int main()
{
    freopen("travel5.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(s2[2] == 'D')
        s2[2] == 'E';
    if(s1[2] == 'D')
        s1[2] == 'E';
    if(c1 == c2)
        cout << 1;
    else
    {
        cout << 0 <<0<< 0 << 0;
        return 0;
    }
    if(s1[0] == s2[0]&&s1[1] == s2[1])
        cout << 1;
    else
    {
        cout << 0 << 0 << 0;
        return 0;
    }
    if(s1[2] <= 'C'&&s2[2] <= 'C'||s1[2] >= 'D'&&s2[2] >= 'D')
    {
        cout << 1;
        a = 1;
    }
    else
    {
        cout << 0 << 0;
        return 0;
    }
    int s = abs(s1[2] - s2[2]);
    if(a == 1 && s == 1)
        cout << 1;
    else
        cout << 0;
    return 0;
}
