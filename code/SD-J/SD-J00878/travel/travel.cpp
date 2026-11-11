#include<bits/stdc++.h>
using namespace std;
int n,m;
string c,s,c1,s1,ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	ans="0000";
	if(c==c1)
	{
		ans="1000";
		if(s[0]==s1[0] && s[1]==s1[1])
		{
		 	ans="1100";
		 	if(s[2]!="C" && s1[2]!="D")
		 	{
		 		 ans="1110";
				 if(abs(s1[2]-s[2])==1)
		 		 ans="1111";
		 		 
			}
			if(s[2]!="D" && s1[2]!="C")
			{
				ans="1110";
		 		if(abs(s1[2]-s[2])==1)
		 		 ans="1111";
			}
		}
	} 
	cout<<ans;
	return 0;
}
