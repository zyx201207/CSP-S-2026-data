#include <bits/stdc++.h>
using namespace std;
long long n,x,ans;
char y;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y;
		for (int j=1;j<=x;j++)
		{
			s+=y;
		}
	}
	for (int i=0;i<=s.length()/2-1;i++)
	{
		if (s[i]!=s[s.length()-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
