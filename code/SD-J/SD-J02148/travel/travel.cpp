#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans+='1';
	else ans+='0';
	if(ans[0]=='1'){
		if(s1[0]==s2[0]&&s1[1]==s2[1]) ans+='1';
		else ans+='0'; 
	}else ans+='0';
	if(ans[1]=='1'){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='D'||s2[2]=='F') ans+='0';
			else ans+='1';
		}else{
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') ans+='0';
			ans+='1';
		}
	}else ans+='0';
	if(ans[2]=='0') ans+='0';
	else{
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||
		(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||
		(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) ans+='1';
		else ans+='0'; 
	} 
	cout<<ans;
	return 0;
} 
