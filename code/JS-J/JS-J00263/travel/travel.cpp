#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool f=1;
    string Rc,Rs,Xc,Xs;
    cin>>Rc>>Rs>>Xc>>Xs;

    if(Rc[0]==Xc[0] && Rc[1]==Xc[1])
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        f=0;
    }

    if(Rs[0]==Xs[0] && Rs[1]==Xs[1] && f==1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        f=0;
    }

    if((Rs[0]==Xs[0] && Rs[1]==Xs[1]) && ((Rs[2]<='C'&&Xs[2]<='C')||(Rs[2]>'C'&&Xs[2]>'C'))&& f==1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        f=0;
    }

    if(f==1 && abs(Rs[2]-Xs[2])==1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;

    }
    return 0;
}
