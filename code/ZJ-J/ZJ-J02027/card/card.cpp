#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[m],cnt[n];
	int t=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]>=a[i-1])
		{
			t++;
		}
		cnt[i]=0;
	}
	int sum=1;
	int b[m],c[m];
	if(t>=n)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i+1])
			{
				sum++;	
			}
			else
			{
				cout << sum << " ";
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				b[i]=0;
				c[i]=0;
			}
			for(int j=i;j<=n;j++)
			{
				if(b[a[j]]==1)
				{
					for(int k=c[a[j]];k<=j;k++)
					{
						b[a[k]]=0;
					}
				}
				b[a[j]]=1;
				c[a[j]]=j;
			}
			for(int j=1;j<=m;j++)
			{
				if(b[j]==1)
				{
					cnt[j]++;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout << cnt[i] << " ";
		}
	}
	return 0;
}
