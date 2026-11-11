#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) cout<<"0000";
    else
    {
        cout<<1;
        int a=s1[0]-s2[0];
        int b=s1[1]-s2[1];
        if(b!=0||a!=0)cout<<"000";
        else
        {
            cout<<1;
            if((s1[2]<='C'&&s2[2]>'C')||(s1[2]>'C'&&s2[2]<='C')) cout<<"00";
            else
            {
                cout<<1;
                int c=s1[2]-s2[2];
                if(c!=1&&c!=-1) cout<<0;
                else cout<<1;
            }
        }
    }
    return 0;
}
