#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    //cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
    if(x1==x2)
    {
        cout<<1;
        if(y1[0]==y2[0]&&y1[1]==y2[1])
        {
            cout<<1;
            if((y1[2]=='D'&&y2[2]=='F')||(y1[2]=='F'&&y2[2]=='D')) cout<<"11";
            else if((y1[2]=='A'&&y2[2]=='B')||(y1[2]=='B'&&y2[2]=='A')) cout<<"11";
            else if((y1[2]=='C'&&y2[2]=='A')||(y1[2]=='A'&&y2[2]=='C')) cout<<"10";
            else if((y1[2]=='B'&&y2[2]=='C')||(y1[2]=='C'&&y2[2]=='B')) cout<<"11";
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
