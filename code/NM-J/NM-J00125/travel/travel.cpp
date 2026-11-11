#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<'1';
        if(b[0]==d[0]&&b[1]==d[1])
        {
            cout<<'1';
            if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
            {
                cout<<'1';
                if(d[2]-b[2]==1)
                {
                    cout<<'1';
                }
                else
                {
                    cout<<'0';
                }
            }
            else
            {
                cout<<'0'<<'0';
            }
        }
        else
        {
            cout<<'0'<<'0'<<'0';
        }
    }
    else
    {
        cout<<'0'<<'0'<<'0'<<'0';
    }

    return 0;
}
