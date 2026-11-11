#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,c1,s1;
	cin>>c>>s>>c1>>s1;
	int newflag=0;
	if(c1==c){
		cout<<1;
		newflag=1;
	}
	else{
		cout<<0;
	}
	int flag=0;
	if(newflag&&s[0]==s1[0]&&s[1]==s1[1]){
		cout<<1;
		flag=1;
	}
	else{
		cout<<0;
	}
	if(flag&&s[2]<='F'&&s[2]>='D'&&s1[2]<='F'&&s1[2]>='D'){
		cout<<1;
	}
	else if(flag&&s[2]<='C'&&s[2]>='A'&&s1[2]<='C'&&s1[2]>='A'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(flag&&((s[2]-1==s1[2]&&s[2]!='D'&&s1[2]!='D')||(s[2]==s1[2]-1&&s[2]!='D'&&s1[2]!='D')||(s1[2]=='D'&&s[2]=='F')||(s1[2]=='F'&&s[2]=='D'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 

