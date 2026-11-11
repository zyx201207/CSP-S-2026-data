#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string Ra,Rb,Xa,Xb;
	cin>>Ra>>Rb>>Xa>>Xb;
	if(Ra==Xa){
		a+="1";
	}
	else{
		a+="0000";
		cout<<a;
		return 0;
	}
	if(Rb[1]==Xb[1]){
		a+="1";
	}
	else{
		a+="000";
		cout<<a;
		return 0;
	}
	if(Rb[2]=='A'||Rb[2]=='B'||Rb[2]=='C'&&Xb[2]=='A'||Xb[2]=='B'||Xb[2]=='C'){
		a+="1";
	}
	else if(Rb[2]=='D'||Rb[2]=='F'&&Xb[2]=='D'||Rb[2]=='F'){
		a+="1";
	}
	else{
		a+="00";
		cout<<a;
		return 0;
	}
	if(fabs(Rb[2]-Xb[2])==1){
		if(Rb[2]=='C'&&Xb[2]=='D'||Rb[2]=='D'&&Xb[2]=='C')
			a+="0";
		else
			a+="1";
	}
	else
		a+="0";
	cout<<a;
	return 0;
}
