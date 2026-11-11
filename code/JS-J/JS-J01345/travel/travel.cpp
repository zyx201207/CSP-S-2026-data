#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        if(s1.substr(0,2)==s2.substr(0,2))
        {
            cout<<"1";
            int a=s1[2],b=s2[2];
            if(a<='C'&&b<='C')
            {
                cout<<"1";
                if(a=='B'||b=='B')
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            else if(a>='D'&&b>='D')
            {
                cout<<"11";
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
