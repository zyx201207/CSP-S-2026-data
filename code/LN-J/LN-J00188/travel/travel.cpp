#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x,y;
    string a,b;
    cin>>x>>a>>y>>b;
    if(x==y)
    {
        cout<<"1";
        if(a[0]==b[0]&&a[1]==b[1])
        {
            cout<<"1";
            if(a[2]=='A'&&b[2]=='B')
            {
                cout<<"11";
            }
            else if(a[2]=='B'&&(b[2]=='A'||b[2]=='C'))
            {
                cout<<"11";
            }
            else if(a[2]=='C'&&b[2]=='B')
            {
                cout<<"11";
            }
            else if(a[2]=='D'&&b[2]=='F')
            {
                cout<<"11";
            }
            else if(a[2]=='F'&&b[2]=='D')
            {
                cout<<"11";
            }
            else if((a[2]=='A'&&b[2]=='C')||(a[2]=='C'&&b[2]=='A'))
            {
                cout<<"10";
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
    fclose(stdin);
    fclose(stdout);
    return 0;
}
