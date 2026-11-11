#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)!=s2.substr(0,2)){
		cout<<"1000";
		return 0;
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<"1100";
		return 0;
	}
	if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')){
		cout<<"1100";
		return 0;
	}
	if(s1[2]=='A'){
		if(s2[2]=='B')cout<<"1111";
		else cout<<"1110";
	}else if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C')cout<<"1111";
		else cout<<"1110";
	}else if(s1[2]=='C'){
		if(s2[2]=='B')cout<<"1111";
		else cout<<"1110";
	}else if(s1[2]=='D'){
		if(s2[2]=='F')cout<<"1111";
		else cout<<"1110";
	}else{
		if(s2[2]=='D')cout<<"1111";
		else cout<<"1110";
	}
}
