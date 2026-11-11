#include<bits/stdc++.h> 
using namespace std;
bool c(string s){
	char a=s[2];
	if('A'<=a&&'C'>=a)return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
	}else if(c(s1)!=c(s2)){
		cout<<"1100";
	}else if(min(s1[2],s2[2])+1!=max(s1[2],s2[2])){
		cout<<"1110";
	}else cout<<"1111";
	return 0;
}
