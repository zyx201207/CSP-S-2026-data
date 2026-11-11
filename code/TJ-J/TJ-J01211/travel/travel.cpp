#include<bits/stdc++.h>
using namespace std;
string rbox,rseat,xbox,xseat;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rbox>>rseat>>xbox>>xseat;
    if(rbox[1]==xbox[1]&&rbox[0]==xbox[0])
    {
        cout<<"1";
        if(rseat[1]==xseat[1]&&rseat[0]==xseat[0])
        {
            cout<<"1";
            if(rseat[2]>'C'&&xseat[2]>'C')
            {
                cout<<"11";
                return 0;
            }
            else if(rseat[2]<='C'&&xseat[2]<='C')
            {
                cout<<"1";
                if(abs(int(rseat[2]-xseat[2]))==1)
                {
                    cout<<"1";
                    return 0;
                }
                else{
                    cout<<"0";
                    return 0;
                }
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
