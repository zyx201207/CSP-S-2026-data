#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,c2;
string s1,s2;
int sum;
bool check1(string c1,string c2){
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			return 0;
		}
	}
	return 1;
}
bool check2(string s1,string s2){
	if(check1(c1,c2)==0){
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			return 0;
		}
	}
	return 1;
}
bool check3(string s1,string s2){
	if(check2(s1,s2)==0){
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='B'){
		return 1;
	}
	if(s1[2]=='A'&&s2[2]=='C'){
		return 1;
	}
	if(s1[2]=='B'&&s2[2]=='A'){
		return 1;
	}
	if(s1[2]=='B'&&s2[2]=='C'){
		return 1;
	}
	if(s1[2]=='C'&&s2[2]=='A'){
		return 1;
	}
	if(s1[2]=='C'&&s2[2]=='B'){
		return 1;
	}
	if(s1[2]=='D'&&s2[2]=='F'){
		return 1;
	}
	if(s1[2]=='F'&&s2[2]=='D'){
		return 1;
	}
	return 0;
}
bool check4(string s1,string s2){
	if(check3(s1,s2)==0){
		return 0;
	}
	else{
		if(abs(s1[2]-s2[2])==1){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<check1(c1,c2)<<check2(s1,s2);
	cout<<check3(s1,s2)<<check4(s1,s2);
	return 0;
}
