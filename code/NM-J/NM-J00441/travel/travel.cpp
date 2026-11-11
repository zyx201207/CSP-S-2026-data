#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>c1>>c2;
    if (s1==c1)
    {
        if(s2[0]==c2[0] && s2[1]==c2[1])
        {
            if(s2[2]>='A' && s2[2]<='C' && c2[2]>='A' && c2[2]<='C')
            {
                if(s2[2]!='B' && c2[2]!='B')
                {
                    cout<<"1110";
                }
                else{
                    cout<<"1111";
                }

            }
            else if ((s2[2]=='D' && c2[2]=='F') || (s2[2]=='F' && c2[2]=='D'))
            {
                cout<<"1111";
            }
            else{
                cout<<"1100";
            }

        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
