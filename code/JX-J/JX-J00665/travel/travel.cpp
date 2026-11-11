#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2,b1,b2,c1,c2;
    string s1,s2;
    cin>>a1>>s1>>a2>>s2;
    b1=(s1[0]-'0')*10+(s1[1]-'0');
    b2=(s2[0]-'0')*10+(s2[1]-'0');
    c1=(s1[2]-'A')+1;
    c2=(s2[2]-'A')+1;
    if(a1!=a2) cout<<"0000";
    else
    {
        cout<<1;
        if(b1!=b2) cout<<"000";
        else
        {
            cout<<1;
            if(c1<=3 and c2<=3)
            {
                cout<<1;
                if(abs(c1-c2)==1) cout<<1;
                else cout<<0;
            }
            else if((c1<=3)^(c2<=3)) cout<<"00";
            else cout<<"11";
        }
    }
    return 0;
}
