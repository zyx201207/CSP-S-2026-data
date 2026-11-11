#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    int s=0;
    cin>>a>>b>>c>>d;
    if (a[0]==c[0])
    {
        if (a[1]==c[1])
        {
            s++;
        }
    }
    if (a[0]==c[0])
    {
        if (a[1]==c[1])
        {
            if (b[0]==d[0])
            {
                if (b[1]==d[1])
                {
                    s++;
                }
            }
        }
    }
    if (a[0]==c[0])
    {
        if (a[1]==c[1])
        {
            if (b[0]==d[0])
            {
                if (b[1]==d[1])
                {
                    if (b[2]=='A' || b[2]=='B' || b[2]=='C')
                    {
                        if (d[2]=='A' || d[2]=='B' || d[2]=='C')
                        {
                            s++;
                            if (b[2]-'0'==d[2]-'0'+1)
                            {
                                s++;
                            }
                            if (b[2]-'0'+1==d[2]-'0')
                            {
                                s++;
                            }
                        }
                    }
                    else
                    {
                        if (d[2]=='D' || d[2]=='F')
                        {
                            s++;
                            if (b[2]-'0'==d[2]-'0'+1)
                            {
                                s++;
                            }
                            if (b[2]-'0'+1==d[2]-'0')
                            {
                                s++;
                            }
                        }
                    }
                }
            }
        }
    }
    if (s==4)
    {
        cout<<1111;
    }
    if (s==3)
    {
        cout<<1110;
    }
    if (s==2)
    {
        cout<<1100;
    }
    if (s==1)
    {
        cout<<1000;
    }
    if (s==0)
    {
        cout<<0<<0<<0<<0;
    }
    return 0;
}
