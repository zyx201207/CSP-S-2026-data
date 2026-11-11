#include<bits/stdc++.h>
using namespace std;
string xc,xz,rc,rz;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>xc>>xz>>rc>>rz;
if(xc==rc)
    {
    cout<<1;
    if(xz[0]==rz[0]&&xz[1]==rz[1])
        {
        cout<<1;
        if((xz[2]<'D'&&rz[2]<'D')||(xz[2]>'C'&&rz[2]>'C'))
            {
            cout<<1;
            char o=xz[2],p=rz[2];
            if((o=='A'&&p=='B'||o=='B'&&p=='A')||(o=='C'&&p=='B'||o=='B'&&p=='C')||(o=='D'&&p=='F'||o=='F'&&p=='D'))
                cout<<1;
            else
                cout<<0;
            }
        else
            cout<<"00";
        }
    else
        cout<<"000";
    }
else
    cout<<"0000";
return 0;
}
