#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a, ans = 0, l = 0;
	string m;
	char b;
	cin>>n;
	for(long long i = 1;i<=n;i++)
	{
		cin>>a>>b;
		for(long long j = 1;j<=a;j++)
		{
			m+=b;
		}
		l+=a;
	}
	for(long long i = 0;i<=l/2;i++)
	{
		if(m[i]!=m[l-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
