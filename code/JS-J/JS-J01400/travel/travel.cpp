
#include<bits/stdc++.h>
using namespace std;
int ai,bi;
string asi,bsi;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ai>>asi>>bi>>bsi;
    if(ai==bi)
        cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(asi[0]==bsi[0]&&asi[1]==bsi[1])
        cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if((asi[2]<='C'&&bsi[2]<='C')||asi[2]>'C'&&bsi[2]>'C')
        cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if(asi[2]-bsi[2]==1||bsi[2]-asi[2]==1)
        cout<<1;
    else
        cout<<0;
    return 0;
}
