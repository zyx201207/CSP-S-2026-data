#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],cnt;
char c[200001];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for (long long j=1;j<=a[i];j++)
		{
			s.push_back(c[i]);
		}
	}
	for (long long i=0;i<s.length()/2;i++)
	{
		if (s[i]!=s[s.length()-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}