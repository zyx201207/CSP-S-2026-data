#include<bits/stdc++.h>
using namespace std;
bool ac(char c1,char c2){
	if(c1-'A'<3&&c2-'A'<3){
		return 1;
	}
	if(c1-'A'>=3&&c2-'A'>=3){
		return 1;
	}
	return 0;
}
bool accepted(char c1,char c2){
	if(abs(int(c1-c2))==1){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(ac(s2[2],s4[2])==1){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(accepted(s2[2],s4[2])==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
