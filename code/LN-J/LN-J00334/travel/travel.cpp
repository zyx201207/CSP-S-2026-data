#include <bits/stdc++.h>
using namespace std;
int main(){
  freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   string x,x1,y,y1;
   cin>>x>>x1>>y>>y1;
   if(x==y)
        cout<<1;
    else {
        cout<<0<<0<<0<<0;
        exit(0);
    }
    if(x1[0]==y1[0]&&x1[1]==y1[1])
        cout<<1;
    else {
        cout<<0<<0<<0;
        exit(0);
    }
    char a=x1[2];
    char b=y1[2];
    if((a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='C'&&b=='A')||(a=='D'&&b=='F')||(a=='F'&&b=='D'))
        cout<<1;
    else{
        cout<<0<<0;
        exit(0);
    }
    if((a=='A'&&b=='B')||(a=='C'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='D'&&b=='F')||(a=='F'&&b=='D'))
        cout<<1;
    else
        cout<<0;

return 0;
}
