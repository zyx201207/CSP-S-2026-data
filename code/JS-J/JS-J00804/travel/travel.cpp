#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1==c2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if (c1==c2&&s1.substr(0,2)==s2.substr(0,2))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if (c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if (c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C')&&abs(s1[2]-s2[2])==1)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    cout << '\n';
    return 0;
}