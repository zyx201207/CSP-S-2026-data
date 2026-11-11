#include <bits/stdc++.h>
using namespace std;
string s1,s2,ss1,ss2;
int s(char c){
	if(c=='A' || c=='B' || c=='C'){
		return 1;
	}
	if(c=='D' || c=='F'){
		return 2;
	}
}
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>s1>>ss1>>s2>>ss2;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			cout<<"0000";
			return 0;
		}
	}
	for(int i=0;i<2;i++){
		if(ss1[i]!=ss2[i]){
			cout<<"1000";
			return 0;
		}
	}
	if(s(ss1[2])!=s(ss2[2])){
		cout<<"1100";
		return 0;
	}else{
		if(abs((int)ss1[2]-(int)ss2[2])==1 || (ss1[2]=='D' && ss2[2]=='F') || (ss2[2]=='D' && ss1[2]=='F')){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1110";
			return 0;
		}
	}
	
	return 0;
}
