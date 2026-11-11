#include<bits/stdc++.h>
using namespace std;
string c,s,c1,s1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c!=c1) cout<<"0000";
	else{
		if(c==c1)cout<<"1";
		else cout<<"0";
		if(c==c1&&s[1]==s1[1]) cout<<"1";
		else cout<<"0";
		if(c==c1&&s[1]==s1[1]&&s[2]<='C'&&s1[2]<='C') cout<<"1";
		else cout<<"0";
		if(c==c1&&s[1]==s1[1]&&((s[2]=='A'&&s1[2]=='B')||(s[2]=='B'&&s1[2]=='A')||(s[2]=='B'&&s1[2]=='C')||(s[2]=='C'&&s1[2]=='B'))) cout<<"1";
		else cout<<"0";
	}
	return 0;
} 
