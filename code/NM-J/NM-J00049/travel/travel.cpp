#include<bits/stdc++.h>
using namespare std;
a[110];
int main({
freopen ("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
if(c1==c2){
a[1]=1;
}else if(c1!=c2){
a[1]=0;
a[2]=0;
a[3]=0;
a[4]=0;
}
if(s1[0]==s2[0]&&a[1]==1){
a[2]=1;
}else if(s1[0!=s2[0]]){
a[2]=0;
a[3]=0;
a[4]=0;
}
if(s1[1]==s2[1]&&a[1]==1&&a[2]==1){
a[3]=1;
}else if(s1[1]!=s2[1]){
a[3]=0;
a[4]=0;
}
if(a[1]==1&&a[2]==1&&a[3]==1){
if('s1[2]'+1=='s2[2]'||'s2[2]'+1=='s1[2]'){

a[4]=1;

}else{
a[4]=0;
}
}
cout<<a[1]<<a[2]<<a[3]<<a[4];
return 0;
}
