#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;

    if(r1==x1)
    {
        cout<<"1";
        if(r2[0]==x2[0]&&r2[1]==x2[1])
        {
            cout<<"1";
            if(r2[2]=='A'&&x2[2]=='C')cout<<"10";return 0;
            if(r2[2]=='C'&&x2[2]=='A')cout<<"10";return 0;
            if(r2[2]=='C'&&x2[2]=='D')cout<<"00";return 0;
            if(r2[2]=='D'&&x2[2]=='C')cout<<"00";return 0;
            if(abs(r2[2]-x2[2])<2)
            {
                if(r2[2]=='A'&&x2[2]=='B')cout<<"11";
                if(r2[2]=='B'&&x2[2]=='A')cout<<"11";
                if(r2[2]=='B'&&x2[2]=='C')cout<<"11";
                if(r2[2]=='C'&&x2[2]=='B')cout<<"11";
                if(r2[2]=='D'&&x2[2]=='F')cout<<"11";
                if(r2[2]=='F'&&x2[2]=='D')cout<<"11";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";


    return 0;
}
