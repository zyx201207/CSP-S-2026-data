#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int n1,n2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        n1=(s1[0]-'0')*10+(s1[1]-'0');
        n2=(s2[0]-'0')*10+(s2[1]-'0');
        if(n1==n2)
        {
            cout<<"1";
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
            {
                cout<<"1";
                if(abs(s1[2]-s2[2])==1)
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
    cout<<endl;
    return 0;
}
