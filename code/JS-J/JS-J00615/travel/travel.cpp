#include<bits/stdc++.h>
using namespace std;
int tr,tx,cr,cx;
char r[5],x[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>tr>>r;
    cin>>tx>>x;
    //Q1
    if(tr==tx){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    //Q2
    if((r[0]==x[0])&&(r[1]==x[1])){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    //Q3
    //what path are them in
    if((int(r[2])>=65)&&int(r[2])<=67){
        cr=1;
    }
    else{
        cr=2;
    }
    if((int(x[2])>=65)&&int(x[2])<=67){
        cx=1;
    }
    else{
        cx=2;
    }
    if(cr==cx){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    //Q4
    if(abs(int(r[2])-int(x[2]))==1){
        cout<<1;
    }
    else{
        cout<<"0";
    }
    return 0;
}
