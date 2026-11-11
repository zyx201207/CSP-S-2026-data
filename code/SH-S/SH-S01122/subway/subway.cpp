#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[50005];
long long a[505][50005];
long long t[505][50005];
long long k[505];
long long rstart[50005];
long long rend[50005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=m;i<m;i++)
	{
		cin>>w[i];
	}
	for(long long i=0;i<n;i++)
	{
		cin>>k[i];
		for(long long j=0;j<k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(long long i=0;i<q;i++)
	{
		cin>>rstart[i]>>rend[i];
	}
	
	return 0;
}
