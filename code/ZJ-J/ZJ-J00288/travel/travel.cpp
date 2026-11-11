#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,s1,s2,s3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	ll vis=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s2[i])
		{
			vis=1;
		}
	}
	if(vis==0) cout<<1;
	else cout<<0;
	
	if(s1[0]==s3[0]&&s1[1]==s3[1]&&(!vis)) cout<<1;
	else cout<<0;
	
	if(s1[0]==s3[0]&&s1[1]==s3[1]&&(!vis))
	{
		if(s1[2]<='C'&&s3[2]<='C') cout<<1;
		else if(s1[2]>'C'&&s3[2]>'C') cout<<1;
		else cout<<0;
	}
	else cout<<0;
	
	if(s1[0]==s3[0]&&s1[1]==s3[1]&&(!vis))
	{
		if(s1[2]<='C'&&s3[2]<='C') 
		{
			if(abs(int(s1[2]-s3[2]))==1) cout<<1;
			else cout<<0;
		}
		else if(s1[2]>'C'&&s3[2]>'C') 
		{
			if(abs(int(s1[2]-s3[2]))==1) cout<<1;
			else cout<<0;
		}
		else cout<<0;
	}
	else cout<<0;
}
