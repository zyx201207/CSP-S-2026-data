#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
string ans;
string s3,s4;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans+='1';
	else ans+='0';
	if(ans[0]=='0') ans+='0';
	else{
		for(int i=0;i<2;i++) s3+=s1[i],s4+=s2[i];
		if(s3==s4) ans+='1';
		else ans+='0';
	}
	if(ans[1]=='0') ans+='0';
	else{
		if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
			if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C') ans+='1';
			else ans+='0';
		}
		else{
			if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C') ans+='0';
			else ans+='1';
		}
	}
	if(ans[2]=='0') ans+='0';
	else{
		if(abs(s2[2]-s1[2]==1)) ans+='1';
		else if((s2[2]=='F' && s1[2]=='D') || (s2[2]=='D' && s1[2]=='F')) ans+='1';
		else ans+='0';
	}
	cout<<ans;
	return 0;
} 
