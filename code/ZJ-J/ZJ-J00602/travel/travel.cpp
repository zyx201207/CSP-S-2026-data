#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool answer1(string c1,string c2){
	if(c1==c2){
		return true;
	}
	return false;
}
bool answer2(string s1,string s2){
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		return true;
	}
	return false;
}
bool answer3(string s1,string s2){
	if(('A'<=s1[2] && s1[2]<='C' && 'A'<=s2[2] && s2[2]<='C')||('E'<=s1[2] && s1[2]<='F' && 'E'<=s2[2] && s2[2]<='F')){
		return true;
	}
	return false;
}
bool answer4(string s1,string s2){
	if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(!answer1(c1,c2)){
		cout<<"0000";
		return 0;
	}
	if(!answer2(s1,s1)){
		cout<<"1000";
		return 0;
	}
	if(!answer3(s1,s2)){
		cout<<"1100";
		return 0;
	}
	if(!answer4(s1,s2)){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
} 
