#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cnt=0,len=0;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		len+=a;
		for(int j=1;j<=a;j++)
		{
			s+=b;
		}
	}
	if(len%2==0)
	{
		for(int i=0;i<len/2;i++)
		{
			s1+=s[i];
		}
		for(int i=len-1;i>=len/2;i--)
		{
			s2+=s[i];
		}
		for(int i=0;i<len/2;i++)
		{
			if(s1[i]!=s2[i])cnt++;
		}
	}
	else
	{
		for(int i=0;i<len/2+1;i++)
		{
			s1+=s[i];
		}
		for(int i=len-1;i>len/2;i--)
		{
			s2+=s[i];
		}
		for(int i=0;i<len/2+1;i++)
		{
			if(s1[i]!=s2[i])cnt++;
		}
	}
	cout<<cnt-1;
	return 0;
}
