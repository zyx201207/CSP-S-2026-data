#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="";
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans+='1';
	else ans+='0';
	if(ans[0]=='1'&&s1[1]==s2[1]) ans+='1';
	else ans+='0';
	if(ans[1]=='1'&&(('A'<=s1[2]&&'C'>=s1[2]&&'A'<=s2[2]&&'C'>=s2[2])||('D'<=s1[2]&&'E'>=s1[2]&&'D'<=s2[2]&&'E'>=s2[2]))) ans+='1';
	else ans+='0';
	if(ans[2]=='1'&&abs(s1[2]-s2[2])==1) ans+='1';
	else ans+='0';
	cout<<ans;
	 
	return 0;
} 
