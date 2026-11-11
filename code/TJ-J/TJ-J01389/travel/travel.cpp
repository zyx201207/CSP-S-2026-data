#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ans="";
	string s,s1;
	string seat,seat1;
	cin>>s>>seat>>s1>>seat1;
	if(s==s1) ans+="1";
	else{
		cout<<"0000";
		return 0;
	}
	string tmp="",tmp1="";
	tmp=seat[0]+seat[1];
	tmp1=seat1[0]+seat1[1];
	if(tmp==tmp1) ans+="1";
	else{
		cout<<"1000";
		return 0;
	}
	if(((seat[2]=='A'||seat[2]=='B')||seat[2]=='C') && (seat1[2]=='A'||seat1[2]=='B')||seat1[2]=='C') ans+="1";
	else if((seat[2]=='D'||seat[2]=='E') && (seat1[2]=='D'||seat1[2]=='E')) ans+="1";
	else{
		cout<<"1100";
		return 0;
	}
	if(seat[2]=='A'){
		if(seat1[2]=='B'){
			cout<<"1111";
			return 0;
		}
	}
	if(seat[2]=='B'){
		if(seat1[2]=='A' || seat1[2]=='C'){
			cout<<"1111";
			return 0;
		}
	}
	if(seat[2]=='C'){
		if(seat1[2]=='B'){
			cout<<"1111";
			return 0;
		}
	}
	if(seat[2]=='D'){
			if(seat1[2]=='E'){
				cout<<"1111";
				return 0;
			}
		}
		if(seat[2]=='E'){
			if(seat1[2]=='D'){
				cout<<"1111";
				return 0;
			}
		}
		cout<<"1110";
		//bjy
}
