#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int a[18][19][6]={0,};
int r,x;
string s1,s2;
cin>>r>>s1>>x>>s2;
int r1=(s1[0]-'0')*10+s1[1]-'0';
int x1=(s2[0]-'0')*10+s2[1]-'0';
int r2=s1[2]-'A'+1;
int x2=s2[2]-'A'+1;
if(r==x){
    cout<<1<<endl;
}
else{
    cout<<0<<endl;
    cout<<0<<endl;
    cout<<0<<endl;
    cout<<0<<endl;
    return 0;
}
    if(r1==x1){
    cout<<1<<endl;
}
else{
    cout<<0<<endl;
    cout<<0<<endl;
    cout<<0<<endl;
    return 0;
}
if((r2<=3&&x2<=3)||(r2>=4&&x2>=4)){
    cout<<1<<endl;
}
else{
    cout<<0<<endl;
    cout<<0<<endl;
    return 0;
}
if(((r2<=3&&x2<=3)||(r2>=4&&x2>=4))&&(r2-x2==1||r2-x2==-1)){
    cout<<1<<endl;
}
else{
    cout<<0<<endl;
}
return 0;}
