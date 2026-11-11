#include<bits/stdc++.h>
using namespace std;
long long n,sum;
string s,c,d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long a;
		string b;
		cin>>a>>b;
		if(n==1)
		{
			cout<<0;
			return 0; 
		}
		for(long long j=1;j<=a;j++)
		{
			s+=b;
		}
	}
	for(long long i=0;i<s.size()/2;i++)
	{
		c+=s[i];
		d+=s[s.size()-i-1];
	}
	for(long long i=0;i<c.size();i++)
	{
		if(c[i]!=d[i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
