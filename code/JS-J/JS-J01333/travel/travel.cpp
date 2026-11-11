#include<bits/stdc++.h>
using namespace std;
int cx[2];
string zw[2],ans="";
int main()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    for(int i=0;i<2;i++)
        cin>>cx[i]>>zw[i];
    if(cx[0]==cx[1])
    {
        ans+='1';
        if((zw[0][0]-'0')*10+zw[0][1]-'0'==(zw[1][0]-'0')*10+zw[1][1]-'0')
        {
            ans+='1';
            if(zw[0][2]=='D'&&zw[1][2]=='F'||zw[0][2]=='C'&&(zw[1][2]=='A'||zw[1][2]=='B')||zw[0][2]=='B'&&(zw[1][2]=='A'||zw[1][2]=='C')||zw[0][2]=='A'&&(zw[1][2]=='C'||zw[1][2]=='B'))
                {
                    ans+='1';
                    if(zw[0][2]+1==zw[1][2]||zw[0][2]-1==zw[1][2])
                        ans+='1';
                    else
                        ans+='0';
                }
            else
                ans+='00';
        }
        else
            ans+='000';
    }
    else
        ans+='0000';
    cout<<ans;
    return 0;
}
