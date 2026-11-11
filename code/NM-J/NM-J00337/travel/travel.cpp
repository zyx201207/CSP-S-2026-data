#include<bits/stdc++.h>
using namespace std;
string c,s,ct,st;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>ct>>st;
	if(c!=ct){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
		if(s[0]==st[0]&&s[1]==st[1]){
			cout<<1;
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	if(((s[2]>='A'&&s[2]<='C')&&(st[2]>='A'&&st[2]<='C')&&s!=st)||((s[2]=='D'&&st[2]=='F')||(s[2]=='F'&&st[2]=='D'))){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if((s[2]>='A'&&s[2]<='C')&&(st[2]>='A'&&st[2]<='C')){
		if(s[2]-st[2]==1||st[2]-s[2]==1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if((s[2]=='D'&&st[2]=='F')||(s[2]=='F'&&st[2]=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	return 0;
}
//以加入图灵派为代价求稳二冲一喵； 
