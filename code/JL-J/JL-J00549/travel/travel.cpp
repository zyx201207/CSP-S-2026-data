#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(b[2]=='A'||b[2]=='B'||b[2]=='C'&&d[2]=='A'||d[2]=='B'||d[2]=='C'||b[2]=='D'||b[2]=='E'&&b[2]=='D'||b[2]=='E'){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(b[2]=='E'||int(b[0]-48)*10+int(b[1]-48)==int(d[0]-48)*10+int(d[1]-48)&&b[2]+1==d[2]||d[2]-1==b[2]||b[2]-1==d[2]||d[2]+1==b[2]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
