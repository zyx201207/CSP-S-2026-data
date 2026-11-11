#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char f,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	f=s1[2],s=s2[2];
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((f=='D'&&s=='F')||(f=='F'&&s=='D')){
		cout<<"11";
		return 0;
	}
	else{
		if(f=='A'&&s=='B'){
			cout<<"11";
			return 0;
		}
		if(f=='A'&&s=='C'){
			cout<<"10";
			return 0;
		}
		if(f=='B'&&s=='A'){
			cout<<"11";
			return 0;
		}
		if(f=='B'&&s=='C'){
			cout<<"11";
			return 0;
		}
		if(f=='C'&&s=='A'){
			cout<<"10";
			return 0;
		}
		if(f=='C'&&s=='B'){
			cout<<"11";
			return 0;
		}
		cout<<"00";
	}
	return 0;
} 
