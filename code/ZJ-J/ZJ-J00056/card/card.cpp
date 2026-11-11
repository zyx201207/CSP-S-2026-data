#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,ar[N],tmp[N],desk[N],cnt[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			tmp[j]=ar[j];
		}
		int sum=0;
		for(int j=i;j<=n;j++)
		{
			int num=tmp[j];
			for(int t=1;t<=sum;t++)
			{
				if(desk[t]==num)
				{
					int tep=sum;
					for(int k=t;k<=tep;k++)
					{
						sum--;
						desk[k]=0;
					}
					break;
				}
			}
			sum++;
			desk[sum]=num;
		}
		for(int j=1;j<=sum;j++)
		{
			cnt[desk[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
