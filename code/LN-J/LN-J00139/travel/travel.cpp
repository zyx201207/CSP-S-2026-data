#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1!=c2)
    {
        cout << "0000";
        return 0;
    }
    else cout << 1;
    int s11 = (s1[0]-'0')*10+(s1[1]-'0')*1;
    int s21 = (s2[0]-'0')*10+(s2[1]-'0')*1;
    if(s11 == s21)
    {
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }
    if(s1[2] == 'A')
    {
        if(s2[2] == 'B') cout << 1;
        else if(s2[2] == 'C') cout << 1;
        else{
            cout << "00";
            return 0;
        }
    }
    if(s1[2] == 'B')
    {
        if(s2[2] == 'A') cout << 1;
        else if(s2[2] == 'C') cout << 1;
        else{
            cout << "00";
            return 0;
        }
    }
    if(s1[2] == 'C')
    {
        if(s2[2] == 'A') cout << 1;
        else if(s2[2] == 'B') cout << 1;
        else{
            cout << "00";
            return 0;
        }
    }
    if(s1[2] == 'D')
    {
        if(s2[2] == 'F') cout << 1;
        else{
            cout << "00";
            return 0;
        }
    }
    if(s1[2] == 'F')
    {
        if(s2[2] == 'D') cout << 1;
        else{
            cout << "00";
            return 0;
        }
    }
    if(abs(s1[2]-s2[2]) == 1) cout << 1;
    else cout << 0;
    return 0;
}
