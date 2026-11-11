#include<bits/stdc++.h>
using namespace std;
string sr,cr,sx,cx;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(flase);
    cin.tie(nullptr);
    cin>>sr>>cr>>sx>>cx;
    if(sr[0]==sx[0]&&sr[1]==sx[1]) cout<<"1";
    else
    {
        cout<<"0000";
        return 0;
    }
    if(cr[0]==cx[0]&&cr[1]==cx[1]) cout<<"1";
    else
    {
        cout<<"000";
        return 0;
    }
    if(cr[2]=='A'||cr[2]=='B'||cr[2]=='C')
    {
        if(cx[2]=='A'||cx[2]=='B'||cx[2]=='C') cout<<"1";
        else
        {
            cout<<"00";
            return 0;
        }
    }
    else if(cr[2]=='D'||cr[2]=='F')
    {
        if(cx[2]=='D'||cx[2]=='F')
        {
            cout<<"11";
            return 0;
        }
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(cr[2]=='A'&&cx[2]=='B') cout<<"1";
    else
    {
        cout<<"0";
        return 0;
    }
    if(cr[2]=='B')
    {
        if(cx[2]=='A'||cx[2]=='C')
        {
            cout<<"1";
            return 0;
        }
        else
        {
            cout<<"0";
            return 0;
        }
    }
    if(cr[2]=='C'&&cx[2]=='B')
    {
        cout<<"1";
        return 0;
    }
    else cout<<"0";
    return 0;
}
