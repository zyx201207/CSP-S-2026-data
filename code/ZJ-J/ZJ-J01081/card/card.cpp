#include <bits/stdc++.h>
using namespace std;

int a[5005];
int cnt[5005];
int sum[5005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i=1;
	int a[5005];
	int cnt[5005];
	int sum[5005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(i<=n)
	{
		int j=i;
		while(j<=n)
		{
			if(sum[a[j]]==1)
			{
				for(int k=1;k<=n;k++)
				{
					sum[k]=0;
				}
			}
			sum[a[j]]++;
			if(j=n)
			{
				for(int k=1;k<=n;k++)
				{
					if(sum[k]==1)
					{
						cnt[k]++;
					}
				}
			}
			j++;
		}
		i++;
	}
	cnt[1]--;
	cnt[m]=n;
	for(int j=1;j<=n;j++)
	{
		if(cnt[j]!=0)
			cout<<cnt[j]<<" ";
	}
	return 0;
}
