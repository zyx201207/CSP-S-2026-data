#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt[3000005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int x=1;x<=n;x++)
	{
		cnt[a[x]]++;
		for(int i=x+1;i<=n;i++)
		{	
			if(a[i]!=a[i-1])
				cnt[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}	
	return 0;
}