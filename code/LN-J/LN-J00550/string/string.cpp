#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, x;
	long long ans = 0;
	char a;
	string s;
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> x >> a;
		for(int j = 1;j<=x;j++)
		{
			s+=a;
		}
	}
	if(s.size()%2==1)
	{
	for(int i = s.size()/2+1;i<s.size();i++)
	{
		if(s[i]!= s[s.size()-i-1])
		{
			ans++;
		}
	}
	cout << ans;
}
else
{
	for(int i = s.size()/2+1;i<s.size();i++)
	{
		if(s[i]!= s[s.size()-i-1])
		{
			ans++;
		}
	}
	if(s[s.size()/2]!=s[s.size()/2-1])
	{
		ans++;
	}
	cout << ans;
}
	return 0;
}
