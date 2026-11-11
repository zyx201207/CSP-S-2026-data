#include<bits/stdc++.h> 
using namespace std;
string s_a1,s_a2,s_b1,s_b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>s_a1>>s_a2>>s_b1>>s_b2;
	if(s_a1!=s_b1){
		cout<<"0000";
		return 0;
	}
	if(s_a2[0]!=s_b2[0]||s_a2[1]!=s_b2[1]){
		cout<<"1000";
		return 0;
	}
	if(((s_a2[2]=='A'||s_a2[2]=='B'||s_a2[2]=='C')&&(s_b2[2]=='D'||s_a2[2]=='F'))||((s_b2[2]=='A'||s_b2[2]=='B'||s_b2[2]=='C')&&(s_a2[2]=='D'||s_a2[2]=='F'))){
		cout<<"1100";
		return 0;
	}
	if(s_a2[2]=='A'&&s_b2[2]!='B'||(s_a2[2]=='B'&&s_b2[2]!='A')&&(s_a2[2]=='B'&&s_b2[2]!='C')||s_a2[2]=='C'&&s_b2[2]!='B'||s_a2[2]=='D'&&s_b2[2]!='F'||s_a2[2]=='F'&&s_b2[2]!='D'){
		cout<<"1110";
		return 0; 
	}
	cout<<"1111";
	return 0;
}
