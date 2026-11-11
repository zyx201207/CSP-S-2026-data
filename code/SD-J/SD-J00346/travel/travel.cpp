#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1;
//---SD-J00346---//
bool check1(string s1,string s2){
	string s1copy=s1.substr(0,2);
	string s2copy=s2.substr(0,2);
	return s1copy==s2copy;
}
bool check2(string s1,string s2){
	if(check1(s1,s2)){
		if(s1[2]<='C'&&s2[2]<='C'){
		return true;
		}else if(s1[2]>='D'&&s2[2]>='D'){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
	
}
bool check3(string s1,string s2){
	if(check1(s1,s2)){
		if(max(s1[2],s2[2])=='D'&&min(s1[2],s2[2])=='C'){
			return false;
		}
		if(max(s1[2],s2[2])==(char)min(s1[2],s2[2])+1){
			return true;
		}if(max(s1[2],s2[2])=='F'&&min(s1[2],s2[2])=='D'){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(check1(s1,s2)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(check2(s1,s2)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(check3(s1,s2)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}






