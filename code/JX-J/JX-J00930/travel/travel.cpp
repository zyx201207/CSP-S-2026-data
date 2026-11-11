#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c1,c2;
    string s1,s2,c3,c4;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    char s3=s1[2],s4=s2[2];

    c3=s1[0]+s1[1];
    c4=s2[0]+s2[1];
    if(c1==c2)
    {
        cout<<"1";
        if(c3==c4)
        {
            cout<<"1";
            if(s3<'D'&&s4<'D')
            {
                cout<<"1";
                if(s3+1==s4||s3-1==s4)
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            else if(s3>='D'&&s4>='D')
            {
                cout<<"1";
                if(s3+1==s4||s3-1==s4)
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
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


    return 0;
}
