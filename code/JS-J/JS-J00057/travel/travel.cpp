#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1[1]==c2[1])
    {
        cout << "1";
    }else{
        cout << "0000";
        return 0;
    }
    if(s1[1]==s2[1])
    {
        cout << "1";
    }else{
        cout << "000";
        return 0;
    }
    if((s1[2]<='C'&& s2[2]<='C')||(s1[2]>='C'&& s2[2]<='C'))
    {
        cout << "1";
    }else{
        cout << "00";
        return 0;
    }
    if((s1[2]=='A'&& s2[2]=='C')||(s1[2]=='C'&& s2[2]=='A'))
    {
        cout << "0";
    }else{
        cout << "1";
    }
    return 0;
}
