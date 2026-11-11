#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
string ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b) ans+="1";
	else ans+="0";
	if(a1[1]==b1[1]&&a1[2]==b1[2])
	{
		ans+="1";
	}
	else ans+="0";
	if(a1[3]=='D'&&b1[3]=='F'||a1[3]=='A'&&b1[3]=='B'||a1[3]=='A'&&b1[3]=='C'||a1[3]=='B'&&b1[3]=='C')
	{
		ans+="1";
	}
	else ans+="0";
	if(a1[3]=='D'&&b1[3]=='F'||a1[3]=='A'&&b1[3]=='B'||a1[3]=='B'&&b1[3]=='C')
	{
		ans+="1";
	}
	else ans+="0";
	cout<<ans;
	return 0;
} 
