#include <bits/stdc++.h>
using namespace std;
int n;
vector<char>s;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a;
	char c;
	for (int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for (long long j=1;j<=a;j++)
			s.push_back(c);
	}
	long long l=s.size();
	for (long long i=0;i<(l+1)/2;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			ans++;
		}
	}
	cout <<ans;
	
	return 0;
} 
