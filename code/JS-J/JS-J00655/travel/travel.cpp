#include<bits/stdc++.h>
#define int long long
using namespace std;
string rc,xc,rh,xh;
int lenr,lenx;
int calc(char ch)
{
    if(ch=='A')
    {
        return 1;
    }
    else if(ch=='B')
    {
        return 2;
    }
    else if(ch=='C')
    {
        return 3;
    }
    else if(ch=='D')
    {
        return 11;
    }
    else if(ch=='F')
    {
        return 12;
    }
    else
    {
        return -10;
    }
}
signed main()
{
    freopen("travel.in","r",stdin);
    // freopen("travel1.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rh>>xc>>xh;
    string pr,px;
    lenr=rh.size();
    lenx=xh.size();
    for(int i=1;i<lenr;i++)
    {
        pr+=rh[i-1];
    }
    for(int i=1;i<lenx;i++)
    {
        px+=xh[i-1];
    }
    if(rc==xc)
    {
        cout<<"1";
        if(pr==px)
        {
            cout<<"1";
            if(abs(calc(rh[lenr-1])-calc(xh[lenx-1]))<=2)
            {
                cout<<"1";
                if(abs(calc(rh[lenr-1])-calc(xh[lenx-1]))==1)
                {
                    cout<<"1\n";
                }
                else
                {
                    cout<<"0\n";
                }
            }
            else
            {
                cout<<"00\n";
            }
        }
        else
        {
            cout<<"000\n";
        }
    }
    else
    {
        cout<<"0000\n";
    }
}