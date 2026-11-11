#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>c2>>s1>>s2;
    bool f1=false,f2=false,f3=false,f4=false;
    if(c1==s1)
    {
        f1=true;
    }
    if((c2[0]==s2[0])&&(c2[1]==s2[1])&&f1)
    {
        f2=true;
    }
    bool x=(c2[2]<='C');
    bool y=(s2[2]<='C');

    if((x==y)&&f2)
    {
        f3=true;
    }
    if(f3&&x)
    {
        if(abs(int(c2[2])-int(s2[2]))==1)
        {
            f4=true;
        }
    }
    if(f3&&!x)
    {
        if(abs(c2[2]-s2[2])==2)
        {
            f4=true;
        }
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}

