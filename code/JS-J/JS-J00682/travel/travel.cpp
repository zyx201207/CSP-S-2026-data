#include<bits/stdc++.h>
using namespace std;
int sh(char a)
{
    if(a=='A'||a=='B'||a=='C') return 1;
    else return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool a,b,c,d;
    a=b=c=d=1;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)   a=0,b=0,c=0,d=0;
    else
    {
        if(!(s1[0]==s2[0]&&s1[1]==s2[1])) b=0,c=0,d=0;
        else
        {
            if(sh(s1[2])!=sh(s2[2])) c=0,d=0;
            else
            {
                if(abs(s1[2]-s2[2])!=1) d=0;
            }
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}
