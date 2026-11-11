#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,b=0;
	long long a[1000010];
	cin >> n >> m;
	for(int i=0 ; i<=n ; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1 ; i<=m ; i++)
	{
		if(a[i]<a[i+1])
		{
			a[i]++;
		}
		else if(a[i]==a[i+1])
		{
			b++;
		}
	}
	cout << b;
	return 0;
}
