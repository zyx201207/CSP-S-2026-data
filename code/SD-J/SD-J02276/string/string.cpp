#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long t;char a;
		cin>>t>>a;
		for(long long j=1;j<=t;j++)
		{
			s+=a;		
		}
	}
	string a=s;
	long long l=s.size();
	reverse(s.begin(),s.end());
	long long ans=0;
	for(long long i=0;i<(l+1)/2;i++)
	{
		if(a[i]!=s[i]) ans++;
	}
	cout<<ans;
	return 0;
} 
