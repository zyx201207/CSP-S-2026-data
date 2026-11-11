#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,n1,n2,p1,p2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    n1=(s1[0]-'0')*10+(s1[1]-'0');
    n2=(s2[0]-'0')*10+(s2[1]-'0');
    p1=s1[2]-'A';
    p2=s2[2]-'A';
    if(c1==c2)
    {
        cout<<1;
        if(n1==n2)
        {
            cout<<1;
            if(p1<=2&&p2<=2)
            {
                cout<<1;
                if(abs(p1-p2)==1)
                {
                    cout<<1;
                    return 0;
                }
                else
                {
                    cout<<0;
                    return 0;
                }
            }
            else if(p1>=3&&p2>=3)
            {
                cout<<"11";
                return 0;
            }
            else
            {
                cout<<"00";
                return 0;
            }
        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    else
    {
        cout<<"0000";
        return 0;
    }
}
