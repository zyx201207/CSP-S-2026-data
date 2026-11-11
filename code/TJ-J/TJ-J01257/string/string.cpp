#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		char s1;
		long long a;
		cin>>a>>s1;
		for(int j=0;j<a;j++)
		{
			s+=s1;
		}
	}
	for(long long i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
