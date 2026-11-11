#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],t[300010],q[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long r=1;
		for(int x=i;x<=n;x++)
		{
			for(int j=1;j<r;j++)
			{
				if(a[x]==q[j])
				{
					r=j;
					break;
				}
			}
			q[r++]=a[x];
		}
		for(int j=1;j<r;j++)
		{
			t[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
