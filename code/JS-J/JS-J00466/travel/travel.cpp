#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a1,b1,c1,d1,e1,a2,b2,c2,d2,e2;
    cin>>a1>>b1>>c1>>d1>>e1>>a2>>b2>>c2>>d2>>e2;
    if(a1==a2&&b1==b2)
    {
        cout<<'1';
        if(c1==c2&&d1==d2)
        {
            cout<<'1';
            if(e1<='C'&&e2<='C'||e1>'C'&&e2>'C')
            {
                cout<<'1';
                if(e2==e1+1||e1==e2+1)
                {
                    cout<<'1';
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
