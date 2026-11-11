#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const long N=510000;
long  n,m,a[N],d[20000][20000],ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(long  i=1;i<=n;i++)
	{
		scanf("%ld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long  i=1;i<=n;i++)
	{
		for(long  j=i+1;j<=n;j++)
		{ 
			d[j][i]=(j-1)*(a[j]-a[j-1])+d[j-1][i];
			if(d[j][i]<=m)
			{
				ans=max(ans,j+1-i);
			}
		} 
	}
	cout<<ans;
	return 0;
 } 
