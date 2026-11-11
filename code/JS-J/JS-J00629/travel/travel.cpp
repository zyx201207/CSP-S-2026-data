#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool s(char p,char q)
{
    if(p=='A'&&q=='B'||p=='A'&&q=='C')
    {
        return 1;
    }
    if(p=='B'&&q=='A'||p=='B'&&q=='C')
    {
        return 1;
    }
    if(p=='C'&&q=='A'||p=='C'&&q=='B')
    {
        return 1;
    }
    if(p=='D'&&q=='F')
    {
        return 1;
    }
    if(p=='F'&&p=='D')
    {
        return 1;
    }
    return 0;
}
bool r(char p,char q)
{
    if(p=='A'&&q=='B')
    {
        return 1;
    }
    if(p=='B'&&q=='A'||p=='B'&&q=='C')
    {
        return 1;
    }
    if(p=='C'&&q=='B')
    {
        return 1;
    }
    if(p=='D'&&p=='F')
    {
        return 1;
    }
    if(p=='F'&&p=='D')
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int x,y;
    x=a[0]*10+a[1];
    y=c[0]*10+c[1];
    if(x==y)
    {
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1])
        {
            cout<<"1";
            char p=b[2],q=d[2];
            if(s(p,q)==1)
            {
                cout<<"1";
                if(r(p,q)==1)
                {
                    cout<<"1";
                }
                else{
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
    else{
        cout<<"0000";
    }
    return 0;
}
