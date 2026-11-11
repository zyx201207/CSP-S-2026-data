#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],s[1000000],c;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		s[a[i]]+=i;
		if(a[i]==a[i-1])
		{
			c=i-1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(c>i)
		{
			cout << "0 ";
		}
		else if(c==i)
		{
			cout << "1 ";
		}
		else
		{
			cout << s[i] << " ";
		}
	}
	return 0;	
} 
