#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,t1,t2;
    cin >> s1 >> s2 >> t1 >> t2;
    if(s1==t1) cout << 1;
    else{
        cout << "0000";
        return 0;
    }
    if(s2[0]+s2[1]==t2[0]+t2[1]) cout << 1;
    else
    {
        cout << "000";
        return 0;
    }
    char a=s2[2],b=t2[2];
    if(a=='A' or a=='B' or a=='C')
    {
        if(b=='A' or b=='B' or b=='C')
        {
            cout << 1;
        }
        else{
            cout << "00";
            return 0;
        }
    }
    else{
        if(b=='D' or b=='F') cout << 1;
        else
        {
            cout << "00";
            return 0;
        }
    }
    if(abs(a-b)==1) cout << 1;
    else cout << 0;
    return 0;
}
