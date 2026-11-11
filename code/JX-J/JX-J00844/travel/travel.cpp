#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        string t1,t2;t1+=s1[0];t1+=s1[1];t2+=s2[0];t2+=s2[1];
        if(t1==t2)
        {
            cout<<1;
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
            {
                cout<<1;
                cout<<((abs(int(s1[2]-s2[2]))==1)&&(!(s1[2]=='C'&&s2[2]=='D'||s2[2]=='C'&&s1[2]=='D')));
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
/*++rp*/
