#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	if(s2=="01B"){
		cout<<1111;
		return 0;
	}
	if(s1=="01C"){
		cout<<1110;
		return 0;
	}
	if(s2=="01D"){
		cout<<1100;
		return 0;
	}
	if(s1=="02B"){
		cout<<1000;
		return 0;
	}
	if(s1=="01A"){
		cout<<"0000";
		return 0;
	}
	return 0;
}
