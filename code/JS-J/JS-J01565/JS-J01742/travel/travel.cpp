#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rc,rb,xc,xb;
    cin>>rc>>rb>>xc>>xb;

    if(rc!=xc)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<"1";

    int tmpa,tmpb;
    tmpa=(rb[0]-'0')*10+(rb[1]-'0');
    tmpb=(xb[0]-'0')*10+(xb[1]-'0');
    if(tmpa!=tmpb)
    {
        cout<<"000"<<endl;
        return 0;
    }
    cout<<"1";

    string rf,xf;
    rf=rb[2],xf=xb[2];
    if(!((rf>="A"&&rf<="C"&&xf>="A"&&xf<="C")||((rf=="D"||rf=="F")&&(xf=="D"||xf=="F"))))
    {
        cout<<"00"<<endl;
        return 0;
    }
    cout<<"1";
    int tmp=rf[0]-xf[0];
    if(abs(tmp)>1&&(rf!="D"&&rf!="F"))
    {
        cout<<"0"<<endl;
        return 0;
    }
    cout<<"1"<<endl;
    return 0;
}
