#include <bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c;
    cin>>b>>d;
    int f=(c[0]-'0')*10+(c[1]-'0');
    int s=(d[0]-'0')*10+(d[1]-'0');
    int e=c[2]-'A';
    int   g=d[2]-'A';
    if(a!=b)
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        if(f==s)
        {
            cout<<"11";
            if(e<=2&&g<=2)
            {
                cout<<"1";
                if(e+1==g||e-1==g)
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            else if(e>=3&&g>=3)
            {
                cout<<"1";
                if(e+1==g||e-1==g)
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

            cout<<"1000";
        }
    }
}
