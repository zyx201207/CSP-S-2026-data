#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long ca,cb;
    string sc,sd;
    cin>>ca>>sc>>cb>>sd;
    if(ca==cb)
    {
        if(sc[0]==sd[0]&&sc[1]==sd[1])
        {
            if(((sc[2]<'D')&&(sd[2]<'D'))||((sc[2]>'C')&&(sd[2]>'C')))
            {
                if((sc[2]>='D'&&sd[2]>='D')||((sc[2]=='A'||sc[2]=='C')&&sd[2]=='B')||(sc[2]=='B'&&(sd[2]=='A'||sd[2]=='C')))
                {
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
