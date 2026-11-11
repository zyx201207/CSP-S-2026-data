#include<bits/stdc++.h>
using namespace std;
long long a[2005],n;
char c[2005];
int main()
{
	freopen("string.in", "r",stdin);
	freopen("string.out","w",stdout);
	cin >> n ;
	string s;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	string s2=s;
	long long hand=0,tail=s.size()-1;
	while(hand<tail)
	{
		if (s2[hand]!=s2[tail])
		{
			s2[tail]=s2[hand];
		}
		hand++;
		tail--;
	}
	long long ans=0;
	for (int i=1;i<=s.size()-1;i++)
	{
		if(s[i]!=s2[i])
		{
			ans++;
		}
	}
	cout << ans;
 } 
 
