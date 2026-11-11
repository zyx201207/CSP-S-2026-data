#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long  n,m;
	cin>>n>>m;
	long long z=0,max[n],sum[n],b[n][n],a[n];
	for(int i=0;i<n;i++)
	{
	max[i]=0;
	sum[i]=0;
	cin>>a[i];
}
	sort(a,a+n,greater<int>());
	for(int w=0;w<n-1;w++)
	{
	for(int i=w+1;i<n;i++)
	{
		b[w][i]=a[w]-a[i];
		if(b[w][i]>m)
		b[w][i]=-202;
		if(b[w][i]==0)
		{
		z++;
		b[w][i]=-101;
	}
		if(b[w][i]!=-202&&b[w][i]!=-101)
		{
		max[w]++;
		sum[w]+=b[w][i];
	}
	}
}
for(int w=0;w<n;w++)
	for(int i=0;i<n;i++)
	{
		if(sum[w]>m)
		{
		sum[w]-=b[w][i];
		max[w]--;
	}
	}
	sort(max,max+n,greater<int>());
	max[0]=max[0]+1+z;
	cout<<max[0];
	return 0;
}
