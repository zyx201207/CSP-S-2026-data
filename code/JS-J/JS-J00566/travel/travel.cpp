#include<bits/stdc++.h>
using namespace std;
char c1[2],c2[2],s1[3],s2[3];
int a[5];
string b="";
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1[0]>>c1[1]>>s1[0]>>s1[1]>>s1[2]>>c2[0]>>c2[1]>>s2[0]>>s2[1]>>s2[2];
if(c1[0]==c2[0]&&c1[1]==c2[1]){
a[1]=1;
if(s1[0]==s2[0]&&s1[1]==s2[1]){
	a[2]=1;
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
	a[3]=1;
	if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)
	a[4]=1;
	}
	if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
	a[3]=1;if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)
	a[4]=1;}
	
}
}
for(int i=1;i<=4;i++){
	if(a[i]==1)
	b+='1';
	else b+='0';
}
cout<<b;
return 0;
}
