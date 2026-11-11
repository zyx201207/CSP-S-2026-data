#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a=0,b=0;
    for(int i=0;i<=1;i++)
    {
        if(c1[i]!=0)
        {
            a=a*10+int(c1[i]-'0');
        }
        if(c2[i]!=0)
        {
            b=b*10+int(c2[i]-'0');
        }
    }
    int x=0,y=0;
    for(int i=0;i<=1;i++)
    {
        if(s1[i]!=0)
        {
            x=x*10+int(s1[i]-'0');
        }
        if(s2[i]!=0)
        {
            y=y*10+int(s2[i]-'0');
        }
    }
    char c=s1[2],d=s2[2];
    if(a==b)
    {
        cout<<'1';
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(x==y)
    {
        cout<<'1';
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if((c<='C' && d<='C') || (c>='D' && d>='D'))
    {
        cout<<'1';
    }
    else
    {
        cout<<"00";
        return 0;
    }
    int f=int(c-'A')+1,g=int(d-'A')+1;
    if(abs(f-g)==1)
    {
        cout<<'1';
    }
    else{
        cout<<'0';
    }
    return 0;
}
