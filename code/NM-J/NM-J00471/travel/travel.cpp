#include<bits/stdc++.h>
using namespace std;
string s;


int main(){
string b1,b2;
int a1,a2;

freopen ("travel.in","r",strdin);

freopen("travel.out","w",strout);
cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
s[1]=1;
}else {
	for(int i=1;i<=4;i++){
		s[i]=0;\
		cout<<s[i];
	}return 0;
}
if(b1[2]==b2[2]){
s[2]=1;
}else {
	for(int i=2;i<=4;i++){
		s[i]=0;
	}for(int i=1;i<=4;i++){
		cout<<s[i];
	}
	return 0;
}
if(b1[3]<='C' and b2[3]<='C' or b1[3]>'C' and b2[3]>'C'){
	s[3]=1;
}else { for(int i=3;i<=4;i++){
	s[i]=0;
}
for(int i=1;i<=4;i++){
	cout<<s[i];
}return 0;
}
if(b1[3]+1==b2[3] or b2[3]+1==b1[3]){
	s[4]=1;
}else s[4]=0;
for(int i=1;i<=4;i++){
	cout<<s[i];
}
for(int i=1;i<=4;i++){
	cout<<s[i];
}
return 0;
	}



