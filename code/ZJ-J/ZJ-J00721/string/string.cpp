#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a;
	char x;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>x;
		for(int i=1;i<=a;i++)
		{
			s+=x;
		}
	}
	string s2;
	for(int i=n;i>=1;i--) s2+=s[i];
	if(n==1 || s==s2)
	{
		cout<<0;
		return 0;
	}
	if(s[0]!=s[n-1])
	{
		cout<<1;
		return 0;
	}
	else
	{
		cout<<2;
	}
	return 0;
}
