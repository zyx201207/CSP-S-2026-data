//Ô­è÷Ðù 440514201308033019 SN-J00174
#include<bits/stdc++.h>
using namespace std;
int a,b;
string s,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>r;
	if(a!=b){
		cout<<"0000";
	}
	else{
		if(s[0]==r[0]&&s[1]==r[1]){
			if((s[2]=='A'&&r[2]=='B')||(s[2]=='B'&&r[2]=='A')||(s[2]=='B'&&r[2]=='C')||(s[2]=='C'&&r[2]=='B')||(s[2]=='D'&&r[2]=='F')||(s[2]=='F'&&r[2]=='D')){
				cout<<1111;
			}
			else if(s[2]=='A'&&r[2]=='C'||s[2]=='C'&&r[2]=='A'){
				cout<<1110;
			}
			else{
				cout<<1100;
			}
		}
		else{
			cout<<1000;
		}
	}
} 
