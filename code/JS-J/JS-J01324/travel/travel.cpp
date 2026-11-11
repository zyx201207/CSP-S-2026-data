#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,y,xx,yy,xxx,yyy,ans1,ans2,ans3,ans4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b>>c>>d;
    if(b[2]=='F') b[2]='E';
    if(d[2]=='F') d[2]='E';

    if(a[0]=='0') x=int(a[1])-48;
    else x=int(a[1])-38;
    if(c[0]=='0') xx=int(c[1])-48;
    else xx=int(c[1])-38;
    if(x==xx) ans1=1;

    if(b[0]=='0') y=int(b[1])-48;
    else y=int(b[1])-38;
    if(d[0]=='0') yy=int(d[1])-48;
    else yy=int(d[1])-38;
    if(ans1==1 && y==yy) ans2=1;

    xxx=int(b[2])-64;
    yyy=int(d[2])-64;
    if((ans1==1) && (ans2==1) && ((xxx<=3&&yyy<=3) || (xxx>3&&yyy>3)))
    {
        ans3=1;
    }

    if(ans1==1 && ans2==1 && ans3==1 && abs(xxx-yyy)==1 && !(xxx==3&&yyy==4) && !(yyy==3&&xxx==4))
    {
        ans4=1;
    }
    cout<<ans1<<ans2<<ans3<<ans4<<endl;
    return 0;
}
