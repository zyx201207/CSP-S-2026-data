#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

string c1,s1,c2,s2;
cin>>c1;
cin>>s1;
cin>>c2;
cin>>s2;
bool pan=s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='D'&&s1[2]!=s2[2];
bool panl=s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&s1[2]!=s2[2];
bool cnt=1;
bool n=1,m=1,b=1;
if(c1==c2){
    cout<<1;

}
else{
    cout<<0;
    n=0;
}
if(s1[0]==s2[0]&&s2[1]==s1[1]&&n){
cout<<1;
}
else{
    cout<<0;
    m=0;
}
if((pan||panl)&&m){
    cout<<1;

}
else{
    cout<<0;
}
if(pan&&m){
    if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
        cout<<1;
        cnt=0;
    }
}
if(panl&&m){
    cout<<1;
    cnt=0;
}
if(cnt){
    cout<<0;
}
return 0;
}
