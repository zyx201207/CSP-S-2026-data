#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int q=s1[2]-'A'+1,w=s2[2]-'A'+1;
    if(c1==c2)
    {
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
            if((q<=3&&w<=3)||(q>=4&&w>=4))
            {
                cout<<1;
                if(abs(q-w)==1)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
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
}
