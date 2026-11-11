#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli n,m,a[500005],v[500005],sum,maxn;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,j;
	cin >> n >> m;
	for (i=1; i<=n; i++)
		cin >> a[i];
	for (i=0; i<pow(n,m); i++) 
	{
		sum=0;
		memset(v,0,sizeof (v));
		for (j=0; j<n; j++)
		{
			if (i&(int)pow(j,m))
			{
				sum++;
				v[j+1]=a[j+1]+1;
			}
		}
		if (sum>m)
			continue;
		sort(v+1,v+1+n,greater<lli>());
		lli maxm; sum=1;
		for (j=2; j<=n; j++)
		{
			if (v[j]==v[j-1])
				sum++;
			else
				sum=1;
			maxm=max(maxm,sum);
		}
		maxn=max(maxn,maxm);
	}
	cout << maxn;
	return 0;
}
