#include<bits/stdc++.h>
using namespace std;
long long int n,m,i,j,l,r,maxn=1,need,a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	b[i]=a[i]+b[i-1];
	for(l=1;l<=n;l++)
	{
		for(r=l+1;r<=n;r++)
		{
			need=0;
			need=(r-l)*a[r]-(b[r-1]-b[l-1]);
			if(need<=m)
			{
				if(r-l+1>maxn)
				maxn=r-l+1;
			}
		}
	}
	cout<<maxn<<endl;
	return 0;
}
