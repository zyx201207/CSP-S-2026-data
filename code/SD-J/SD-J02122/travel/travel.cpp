#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if (s1!=s3){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
	}
	if (s2.substr(0,2)==s4.substr(0,2)){
		cout<<1;
	}
	else {
		cout<<0;
	}
	if (s2.substr(0,2)==s4.substr(0,2)){
		if (((s2[2]=='F'&&s4[2]=='D')||(s2[2]=='D'&&s4[2]=='F'))){
			cout<<1;
		}
		else if ((s2[2]>='A'&&s2[2]<='C')&&(s4[2]>='A'&&s4[2]<='C')){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	if (s2.substr(0,2)==s4.substr(0,2)){
		if (((s2[2]=='F'&&s4[2]=='D')||(s2[2]=='D'&&s4[2]=='F'))){
			cout<<1;
		}
		else if (abs(s2[2]-s4[2])==1&&!((s2[2]=='C'&&s4[2]=='D')||(s2[2]=='D'&&s4[2]=='C'))){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else {
		cout<<0;
	}
	return 0;
} 
