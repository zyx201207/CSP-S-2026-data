#include <bits/stdc++.h>
using namespace std;
bool flag(string a,string b)
{
    if(a[2]<='C'&&b[2]>='D'||a[2]>='C'&&b[2]<='D')
    {
        return 0;
    }
    return 1;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2)
    {
        cout << "1";
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout << "1";
            if(flag(s1,s2))
            {
                cout << "1";
                if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
                {
                    cout<<"1";
                }
                else
                {
                    cout <<"0";
                }
            }
            else
            {
                cout << "00";
            }
        }
        else
        {
            cout << "000";
        }
    }
    else
    {
        cout << "0000";
        return 0;
    }
    return 0;
}
