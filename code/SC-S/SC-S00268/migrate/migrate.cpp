#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
using namespace std;
const int N=2e6+5;
int c,t,s;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		long long a[N];
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if((a[3]-a[1])>d)
		{
			cout<<0<<endl;
		}
		else
		{
			int ma=0;
			for(int i=1;i<=n;i++)
			{
				ma=n-i+ma;
			}
			cout<<ma<<endl;
		}
	} 
	return 0;
}