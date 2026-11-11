#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int q,w,e,r,x,y;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(b[2]=='A' or b[2]=='C')
        x=0;
    else if(b[2]=='B')
        x=1;
    else
        x=3;

    if(d[2]=='A' or d[2]=='C')
        y=0;
    else if(d[2]=='B')
        y=1;
    else
        y=3;
    if(a==c)
    {
        q=1;
        if(b[0]==d[0] and b[1]==d[1])
        {
            w=1;
            if(x<2 and y<2 or x>2 and y>2)
            {
                e=1;
                if(x+y==1 or x+y==6)
                    r=1;
                else
                    r=0;
            }
            else
            {
                e=0,r=0;
            }
        }
        else
        {
            w=0,e=0,r=0;
        }
    }
    else
    {
        q=0,w=0,e=0,r=0;
    }
    cout<<q<<w<<e<<r;
    return 0;
}
