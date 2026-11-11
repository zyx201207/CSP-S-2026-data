#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long s[100050];
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	long long maxx=1;
	for (int i=1;i<=20;i++)
	{
		maxx*=2;
	}
	maxx--;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	while(m--)
	{
		for (int i=1;i<=n;i++)
		{
			maxx=s[i];
			for (int j=1;j<=n;j++)
			{
				maxx=max(maxx&s[i],maxx&s[j]);
			}
		}
	}
	cout<<maxx;
	return 0;
} 
