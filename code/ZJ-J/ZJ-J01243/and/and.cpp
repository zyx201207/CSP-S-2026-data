#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200001],maxx=pow(2,30)-1,collect[200001];
	int m,n,two[31];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long x=a[i],v=0;
		while(x>0)
		{
			if(x%2==1) two[v]++;
			x=x>>1;
			v++;
		}
	}
	int j=30;
	while(two[j]<m&&j>=0) j--;
	if(j==-1)
	{
		cout<<0;
		return 0;
	}
	int t=0,i=1;
	while(t<m)
	{
		if((a[i]>>j)%2==1)
		{
			t++;
			maxx=maxx & a[i];
		}
		i++;
	}
	cout<<maxx;
	return 0;
} 