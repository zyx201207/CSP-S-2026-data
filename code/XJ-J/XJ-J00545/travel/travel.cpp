#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	int a=0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]!=s2[2]){
		cout<<"1";
		a=1;
	}else{
		cout<<"0";
		a=0;
	}
	if((s1[3]<'D'&&s2[3]<'D')&&((s1[3]<'F'&&s2[3]<'F')&&(s1[3]>'D'&&s2[3]>'D'))&&((s1[3]!='C'&&s2[3]!='D')&&(s2[3]!='C'&&s1[3]!='D'))){
		cout<<"1";
		a=1;
	}else{
		cout<<"0";
		a=0;
	}
	if(a==1&&(s1[2]+'32'==s2[2])||(s2[2]+'32'==s1[2])){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}