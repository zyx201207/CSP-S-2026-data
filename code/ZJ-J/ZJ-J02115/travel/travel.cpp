#include<bits/stdc++.h>
using namespace std;
string s[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<4;i++){
		cin>>s[i];
	}
	if(s[0][1]-'0'!=s[2][1]-'0'){
		cout<<"0000";
		return 0;
	}
	if(s[1][1]-'0'!=s[3][1]-'0'){
		cout<<"1000";
		return 0;
	}
	if(!(s[1][2]=='A'||s[1][2]=='B'||s[1][2]=='C'&&s[3][2]=='A'||s[3][2]=='B'||s[3][2]=='C')||(s[1][2]=='D'||s[1][2]=='F'&&s[3][2]=='D'||s[3][2]=='F')){
		cout<<"1100";
	}
	else{
		if(s[1][2]=='D'||s[1][2]=='F') cout<<"1111";
		else{
			if((s[1][2]=='A'&&s[3][2]=='C')||(s[3][2]=='A'&&s[1][2]=='C')) cout<<"1110";
			else cout<<"1111";
		}
	}
	return 0;
}