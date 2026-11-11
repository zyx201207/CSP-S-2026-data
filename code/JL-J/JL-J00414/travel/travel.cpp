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
        cout<<"1";
        string p1,p2;

        char z1,z2;
        p1=s1[0]+s1[1];
        p2=s2[0]+s2[1];
        z1=s1[2];
        z2=s2[2];
        if(p1==p2)
        {
            cout<<"1";
            if(((z1>='A'&&z1<='C')&&(z2>='A'&&z2<='C'))||((z1>='D'&&z1<='F')&&(z2>='D'&&z2<='F')))
            {
                cout<<"1";
                int a=(int)z1-z2;
                if(a==1||a==-1)
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
    return 0;
}
