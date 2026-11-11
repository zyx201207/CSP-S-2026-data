#include <bits/stdc++.h>
using namespace std;
char a1[10],a2[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,z1,z2,c="";
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<3;i++)
    {
        a1[i]=s1[i];
        a2[i]=s2[i];
        if(a1[i]=='F')
            a1[i]='E';
        if(a2[i]=='F')
            a2[i]='E';
    }
    z1=a1[0]+a1[1];
    z2=a2[0]+a2[1];
    if(c1==c2)
    {
        c=c+"1";
        if(z1==z2)
        {
            c=c+"1";
            if((a1[2]>='A'&&a1[2]<='C'&&a2[2]>='A'&&a2[2]<='C')||(a1[2]>='D'&&a1[2]<='E'&&a2[2]>='D'&&a2[2]<='E'))
            {
                c=c+"1";
                if(a1[2]+1==a2[2]||a1[2]-1==a2[2])
                    c=c+"1";
                else
                    c=c+"0";
            }
            else
            {
                c=c+"0";
                c=c+"0";
            }
        }
        else
        {
            c=c+"0";
            c=c+"0";
            c=c+"0";
        }
    }
    else
    {
        c=c+"0";
        c=c+"0";
        c=c+"0";
        c=c+"0";
    }
    cout<<c;
    return 0;
}
