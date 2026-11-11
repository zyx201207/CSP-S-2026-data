#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int aaa=0;
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
if(c1==c2){
	cout<<1;
}
else{
	cout<<"0000";
	return 0;
}
if(s1[0]==s2[0]&&s1[1]==s2[1]){
	cout<<1;
}
else{
	cout<<"000";
	return 0;
}
if('A'<=s1[2]&&s1[2]<='C'){
	if('A'<=s2[2]&&s2[2]<='C'){
		aaa=1;
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
}
else if('D'<=s1[2]&&s1[2]<='F'){
	if('D'<=s2[2]&&s2[2]<='F'){
		aaa=1;
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
}
else{
	cout<<"00";
	return 0;
}
if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'){
cout<<0;	
}
else{
cout<<1;
}
return 0;
}
