#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[200001],f[200001][41],num[41],flag[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	cin>>a[i],flag[i]=1;
	for(long long i=1;i<=n;i++)
	{
		long long j=1;
		long long v=a[i];
		while(v)
		{
			if(v%2) f[i][j]=1,num[j]++;
			v/=2;
			j++;
		}
	}
	for(long long j=40;j>=1;j--)
	{
		if(num[j]>=m) 
		{
			ans+=pow(2,j-1);
			for(long long i=1;i<=n;i++)
			{
				if(f[i][j]==0) flag[i]=0;
			}
			for(long long k=40;k>=1;k--) num[k]=0;
			for(long long i=1;i<=n;i++)
			{
				long long k=1;
				long long v=a[i];
				if(flag[i]==1)
				{
					while(v)
					{
						if(v%2) f[i][k]=1,num[k]++;
						v/=2;
						k++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
