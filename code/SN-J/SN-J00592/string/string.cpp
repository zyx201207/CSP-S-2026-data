#include <bits/stdc++.h>
using namespace std;
int tick[200005];
int main ()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int n;
	long long sum=0;
	long long  a[200005];
	char c[200005];
	cin >> n; 
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
	}
	string s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(int i=0;i<=n/2+1;i++)
	{
		if(s[i]==s[n+1-i])
		{
			tick[i]=1;
		}
		else 
		{
			s[i]=s[n+1-i];
			sum++;
		}
	}
	cout << sum;
	return 0;
}
