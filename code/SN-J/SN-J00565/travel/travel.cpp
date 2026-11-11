#include<bits/stdc++.h>
using namespace std;
int co,ct,po,pt;
string so,st;
bool check(){
	if(so=="A"||so=="B"||so=="C"){
		if(st=="A"||st=="B"||st=="C"){
			return 1;
		}else{
			return 0;
		}
	}else{
		if(st=="A"||st=="B"||st=="C"){
			return 0;
		}else{
			return 1;
		}
	}
}
bool check1(){
	if(so=="A"&&st=="B") return 1;
	if(so=="B"&&st=="A") return 1;
	if(so=="B"&&st=="C") return 1;
	if(so=="C"&&st=="B") return 1;
	if(so=="D"&&st=="F") return 1;
	if(so=="F"&&st=="D") return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>co>>so>>ct>>st;
	po=(so[0]-'0')*10+(so[1]-'0');
	pt=(st[0]-'0')*10+(st[1]-'0');
	so=so[2];
	st=st[2];
	if(co==ct){
		cout<<1;
	}else{
		cout<<0;
	}
	if(co==ct&&po==pt){
		cout<<1;
	}else{
		cout<<0;
	}
	if(co==ct&&po==pt&&check()){
		cout<<1;
	}else{
		cout<<0;
	}
	if(co==ct&&po==pt&&check()&&check1()){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
