#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,ans;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)ans+='1';
	else ans+='0';
	if(ans[0]=='0')ans+='0';
	else if(s2[0]==s4[0]&&s2[1]==s4[1])ans+='1';
	else ans+='0';
	char a=s2[2],b=s4[2];
		
	if(ans[1]=='0')ans+='0';
	else if(a<='C'&&b<='C')ans+='1';
	else if(a>='D'&&b>='D')ans+='1';
	else ans+='0';
	char l=min(a,b),r=max(a,b);
	
	if(ans[2]=='0')ans+='0';
	else if(r==l+1&&l<='B')ans+='1';
	else if(r=='F'&&l=='D')ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}
