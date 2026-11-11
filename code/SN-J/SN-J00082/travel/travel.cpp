#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	} 
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
	else cout<<"0";
	if(int(s2[2])>='A'&&int(s2[2])<='c'){
		if(int(s1[2])>='A'&&int(s1[2])<='c'){
			cout<<"1";
			if(int(s2[2])+1==int(s1[2])) cout<<"1";
			else if(int(s2[2])-1==int(s1[2])) cout<<"1";
			else cout<<"0";
	}
		else cout<<"00";
	}
	else if(s2[2]=='D'||s2[2]=='F'){
		if(s1[2]=='D'||s1[2]=='F')cout<<"11";
	}
	else cout<<"0";
	return 0;
} 
