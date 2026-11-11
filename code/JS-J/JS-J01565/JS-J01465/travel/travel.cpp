#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int tx,tp,tc,xl;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cr>>sr>>cx>>sx;
    if(cr==cx) tx=1;
    if(tx==1&&sr[0]+sr[1]==sx[0]+sx[1]) tp=1;
    if(tp==1&&sr[2]<='C'&&sx[2]<='C') tc=1;
    else if(tp==1&&sr[2]>='D'&&sx[2]>='D') tc=1;
    if(tp==1)
    {
        if(tc==1&&char(sr[2])==char(sx[2])+1)  xl=1;
        else if(tc==1&&char(sr[2])==char(sx[2])-1)  xl=1;
    }
    else if(tx==1&&int(sr[0]+sr[1])==int(sx[0]+sx[1])-1) if(sr[2]==sx[2]) xl=1;
    else if(tx==1&&int(sr[0]+sr[1])==int(sx[0]+sx[1])+1) if(sr[2]==sx[2]) xl=1;
    cout<<tx<<tp<<tc<<xl;
    return 0;
}
