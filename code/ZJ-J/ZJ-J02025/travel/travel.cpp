#include<bits/stdc++.h>
using namespace std;
#define int long long

bool check_tc(char a,char b){
	if(a>='D' && b>='D')return true;
	if(a<='C' && b<='C')return true;
	return false;
}

bool check_xl(char a,char b){
	if(a>b){
		char c=b;
		b=a;
		a=c;
	}
	if(a=='D'){
		if(b=='F')return true;
		else return false;
	}else{
		if(a=='C')return false;
		if(a=='B'){
			if(b=='C')return true;
			else return false;
		}
		if(a=='A'){
			if(b=='B')return true;
			else return false;
		}
	}
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(check_tc(s1[2],s2[2])){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(check_xl(s1[2],s2[2])){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
