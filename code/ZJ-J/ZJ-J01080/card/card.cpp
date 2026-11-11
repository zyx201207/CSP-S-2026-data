#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int cnt[5000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[5000],b[5000];
	cin>>n>>m;																															
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int z=i;z<=j;z++)
			if(a[j]==a[z]&&j!=z)
			{
				for(int f=z+1,q=j+1;f<=j;f++,q++)
				a[f]=a[q];
			}
		}
		for(int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			a[j]=b[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
