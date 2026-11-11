#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
   int t=1;
    string c,x,cc,xx;
    cin>>c>>x>>cc>>xx;
    if(c==cc&&t==1){
        cout<<1;
    }
    else{
        cout<<0;
        t=0;
    }
    string d="",r="";
    d+=x[0];
    d+=x[1];
    r+=xx[0];
    r+=xx[1];
    if(d==r&&t==1){
        cout<<1;
    }
    else{
        cout<<0;
        t=0;
    }
   if(t==1){
    if((x[2]=='A'||x[2]=='B'||x[2]=='C')&&(xx[2]=='A'||xx[2]=='B'||xx[2]=='C')){
        cout<<1;
    }
    else if((x[2]=='D'||x[2]=='F')&&(xx[2]=='D'||xx[2]=='F')){
        cout<<1;
    }
    else{
        cout<<0;
        t=0;
    }
   }
   else{
    cout<<0;
    t=0;
   }
   if(t==1){
    if((x[2]=='A'||x[2]=='B')&&(xx[2]=='A'||xx[2]=='B')){
        cout<<1;
    }
    else if((x[2]=='B'||x[2]=='C')&&(xx[2]=='B'||xx[2]=='C')){
     cout<<1;
    }
    else if((x[2]=='D'||x[2]=='F')&&(xx[2]=='D'||xx[2]=='F')){
        cout<<1;
    }
    else{
        cout<<0;
        t=0;
    }
   }
   else{
    cout<<0;
    t=0;
   }
    return 0;
}
