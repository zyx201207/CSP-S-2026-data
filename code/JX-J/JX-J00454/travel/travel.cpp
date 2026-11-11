#include<iostream>;
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
int a,b;
if(s1==s2){
cout<<1;
}
for(int i=0;i<2;i++){
    a+=int (c1[i]);
    b+=int (c2[i]);

}
if(a==b){
cout<<1;
}
else{
cout<<0;
}
if(c1[3]!=c2[3] and ((c1[3]>='A' and c1[3]<='C' and c2[3]>='A' and c2[3]<='C') or( c1[3]>='D' and c1[3]<='F' and c2[3]>='D' and c2[3]<='F'))){
    cout<<1;
}
else{
cout<<0;
}

if(c1[3]-c2[3]==1 or (c1[3]=='D' and c2[3]=='F') or (c1[3]=='F' and c2[3]=='D')){
    cout<<1;
}
else{
cout<<0;
}
return 0;
}
