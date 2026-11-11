#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	string x1=s1.substr(0,2);
	string x2=s2.substr(0,2);
	if(x1==x2){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
		cout<<'1';
	}
	else{
		if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
			cout<<'1';
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
		cout<<'0';
		return 0;
	}
	else{
		if(abs(s1[2]-s2[2])==1){
			cout<<'1';
			return 0;
		}
		else{
			cout<<'0';
		}
	}
	return 0;
}
