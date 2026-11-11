#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],sum[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int nn=n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int u=1;u<=nn;u++)
	{
		int k[N]={},ans=0;
		for(int i=1;i<=n;i++)
		{	
			ans++;
			k[ans]=a[i];
			for(int j=1;j<ans;j++)
			{
				if(a[i]==k[j])
				{
					for(int l=1;l<=ans;l++)
						k[l]=0;
					k[1]=a[i];
					ans=1;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
			sum[k[i]]++;
		for(int i=2;i<=n;i++)
			a[i-1]=a[i];
		n--;
	}
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<' ';
	return 0;
}
