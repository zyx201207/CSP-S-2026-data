#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w ",stdout);
    int a,c;
    string b,d;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    int x,y;
    x=b[0]-'0';
    x*=10;
    x+=b[1]-'0';
    y=d[0]-'0';
    y*=10;
    y+=d[1]-'0';
    if(a==c){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(x==y){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(b[2]=='A'&&d[2]=='B'||b[2]=='A'&&d[2]=='C'||b[2]=='B'&&d[2]=='C'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D') cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(b[2]=='A'&&d[2]=='B'||d[2]=='A'&&b[2]=='B'||b[2]=='C'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D') cout<<1;
    else cout<<0;
    return 0;
}
