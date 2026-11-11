#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
   freopen("travel5.in","r",stdin);
    freopen("travel.out","W",stdout);
    cin>>a>>b>>c>>d;
    if(a==c) cout<<1;
    else{cout<<"0000"; return 0;}
    if((b[0]+b[1])==(d[0]+d[1])) cout<<1;
    else {cout<<"000"; return 0;}
    if((b[2]=='C'&&d[2]=='D')||(d[2]=='D'&&b[2]=='C')){ cout<<00;return 0;}
    else if((b[2]=='C'&&d[2]=='A')||(d[2]=='C'&&b[2]=='A')){cout<<"10"; return 0;}
    else if((d[2]-b[2])==1||(b[2]-d[2])==1) cout<<"11";
    else cout<<"00";
    return 0;

}
