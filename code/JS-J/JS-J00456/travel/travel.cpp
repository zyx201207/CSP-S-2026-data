#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    if(c1==c2)
    {
        cout<<"1";
 //       cout<<"\n";
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<"1";
//            cout<<"\n";
            if(s1[2]+s2[2]=='D'+'F'||s1[2]+s2[2]=='A'+'B'||s1[2]+s2[2]=='B'+'C')
            {
                cout<<"11";
            }
            else
            {
                if(s1[2]+s2[2]=='A'+'C')
                {
                    cout<<"10";
                }
                else
                {
                    cout<<"00";
                }

            }
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
    return 0;
}
