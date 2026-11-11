#include <bits/stdc++.h>
using namespace std;
string c1,c2;
char s1,s2;
int cs1,cs2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>cs1>>s1>>c2>>cs2>>s2;
    if(c1==c2)
    {
        cout<<1;

        if(cs1==cs2)
        {
            cout<<1;
            if(s1<='B'&&s2<='B'||s1>='C'&&s2>='C')
            {
                cout<<1;
                if(abs(s1-s2)==1)
                    cout<<1;
                else
                    cout<<0;
            }
            else
                cout<<"00";
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";

        return 0;


}
