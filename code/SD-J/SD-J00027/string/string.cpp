#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,a,ans=0,cd=0;
	char c;
	string s;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		cd+=a;
		while(a--)
		{
			s+=c;	
		}
	}
	for(long long i=0;i<cd;i++)
	{
		if(s[i]==s[cd-i-1])
		{
			continue;
		}
		if(s[i]!=s[cd-i-1])
		{
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
 } 
