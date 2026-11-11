#include<bits/stdc++.h>
using namespace std;
struct T{
string zj,zw;
}a[3];
int x,y;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a[1].zj>>a[1].zw;
cin>>a[2].zj>>a[2].zw;
if(a[1].zj==a[2].zj){
    cout<<1;
}
else{
    cout<<"0000";
    return 0;
}
if(a[1].zw[0]==a[2].zw[0]&&a[1].zw[1]==a[2].zw[1]){
    cout<<1;
}
else{
    cout<<"000";
    return 0;
}
if(a[1].zw[2]=='A'||a[1].zw[2]=='B'||a[1].zw[2]=='C'){
    x=1;
}
if(a[2].zw[2]=='A'||a[2].zw[2]=='B'||a[2].zw[2]=='C'){
    y=1;
}
if(x==y){
    cout<<1;
    if(a[2].zw[2]==a[1].zw[2]+1||a[1].zw[2]==a[2].zw[2]+1||a[1].zw[2]=='D'&&a[2].zw[2]=='F'||a[1].zw[2]=='F'&&a[2].zw[2]=='D'){
        cout<<1;
    }
    else{
        cout<<0;
    }
}
else{
    cout<<0;
    cout<<0;
}
return 0;
}
