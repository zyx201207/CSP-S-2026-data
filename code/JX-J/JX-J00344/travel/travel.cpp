#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,x,y;
    cin>>a>>b>>x>>y;
    if(a[0]==x[0]&&a[1]==x[1])
    {
        cout<<"1";
        if(b[0]==y[0]&&b[1]==y[1])
        {
            cout<<"1";
            if(b[2]=='A'||b[2]=='B'||b[2]=='C')
            {
                if(y[2]=='A'||y[2]=='B'||y[2]=='C')
                {
                    cout<<"1";
                    if((b[2]=='A'&&y[2]=='B')||(y[2]=='A'&&b[2]=='B')||(b[2]=='B'&&y[2]=='C')||(y[2]=='B'&&b[2]=='C'))
                    {
                        cout<<"1";

                    }
                    else{
                        cout<<"0";
                    }

                }
                else{
                    cout<<"00";
                }

            }
            else if(b[2]=='D'||b[2]=='F')
            {
                if(y[2]=='D'||y[2]=='F')
                {
                    cout<<"11";

                }
                else{
                    cout<<"00";
                }

            }


        }
        else
        {
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }

    return 0;
}
