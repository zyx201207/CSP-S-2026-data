include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
char s1[2],c1[3],s2[2],c2[3];
cin>>s1[0]>>s1[1]>>c1[0]>>c1[1]>>c1[2]>>s2[0]>>s2[1]>>c2[0]>>c2[1]>>c2[2];
if(s1[0]==s2[0] && s1[1]==s2[1]){
cout<<'1';
if(c1[0]==c2[0] && c1[1]==c2[1]){
cout<<'1';
if((c1[2]>='D' && c2[2]>='D') || (c1[2]<='C' && c2[2]<='C')){
cout<<'1';
if(abs(c1[2]-c2[2]==1){
cout<<'1';
}else{
cout<<'0';
}
}else{
cout<<"00";
}
}else{
cout<<"000";
}
}else{
cout<<"0000";
}
fclose(stdin);
fclose(stdout);
return 0;
}
