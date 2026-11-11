#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cx,cy,sx,sy,ax,ay,bx,by;
    cin>>cx>>sx>>cy>>sy;
    ax=sx[0]+sx[1];
    ay=sy[0]+sy[1];
    bx=sx[2];
    by=sy[2];
    if(cx==cy)
    {
        cout<<"1";
        if(ax==ay)
        {
            cout<<1;
            if(bx=="A"&&by=="B"||by=="A"&&bx=="B"||bx=="B"&&by=="C"||by=="B"&&bx=="C"||bx=="D"&&by=="F"||by=="D"&&bx=="F")
            {
                cout<<"11";
            }
            else if(bx=="A"&&by=="C"||by=="A"&&bx=="C")
            {
                cout<<"10";
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    return 0;

}
