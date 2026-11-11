#include <bits/stdc++.h>
using namespace std;
int n,m,o,sum,mx;
int a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[j]=1e9;
			if(a[j]-a[i]>0)
			{
				
			}
			else
			{
				b[j]=a[i]-a[j];
			}
		}
		sort(b+1,b+n+1);
		o=1;
		int m1=m;
		sum=0;
		while(1)
		{
			if(m-b[o]<0)break;
			sum++;
			m-=b[o];
			o++;
		}
		mx=max(mx,sum);
		sum=0;
		m=m1;
}
	cout<<mx;
	return 0;
 } 