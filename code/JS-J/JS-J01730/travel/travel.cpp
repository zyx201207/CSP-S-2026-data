#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);//T1: 8:40~9:00
    freopen("travel.out","w",stdout);//hp:100
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){//q1
        cout<<"0000";
        return 0;
    }else{
        cout<<1;
    }

    if(b[0]==d[0]&&b[1]==d[1]){//q2
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }

    char x=b[2],y=d[2];//q3
    if(x<y){
        swap(x,y);
    }if(x<'D'&&y<   'D'){
        cout<<1;
    }else if(x>='D'&&y>='D'){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }

    if(x=='F'&&y=='D'){//q4
        cout<<1;
    }else if(x=='B'&&y=='A'){
        cout<<1;
    }else if(x=='C'&&y=='B'){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
