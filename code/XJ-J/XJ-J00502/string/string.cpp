#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,s1,s2;
	char t;
	long long int l,i,j,n,num,ans;
	ans=0;
	l=1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>num>>t;
		l=l+num; 
		while(num--)
		{
			s=s+t;
		}
	}
	if(l%2==0)
	{
		for(i=0;i<=l/2-2;i++)
		{
			s1+=s[i];
		}
		for(i=l/2;i<l;i++)
		{
			s2+=s[i];
		}
		for(i=0;i<=l/2-2;i++)
		{
			if(s1[i]!=s2[i]) ans++;
		}
	}
	else 
	{
		for(i=0;i<l/2-1;i++)
		{
			s1+=s[i];
		}
		for(i=l/2;i<l;i++)
		{
			s2+=s[i];
		}
		for(i=0;i<=l/2-1;i++)
		{
			if(s1[i]!=s2[i]) ans++;
		}
	}
	cout<<ans;
	return 0;
}