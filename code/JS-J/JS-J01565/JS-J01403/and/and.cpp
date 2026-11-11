#include<bits/stdc++.h>
using namespace std;
long long n,m,f,ans,maxx,a[200005],fenjie[200005][35],beijian[35],cun[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==1) cout<<maxx;
	for(long long i=1;i<=maxx;i*=2)
	{
		f++;
	}
	beijian[f]=1;
	for(long long i=f-1;i>=1;i--)
	{
		beijian[i]=beijian[i+1]*2;
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=f;j++)
		{
			if(a[i]>=beijian[j])
			{
				fenjie[i][j]=beijian[j];
				a[i]-=beijian[j];
			}
			else
			{
				fenjie[i][j]=0;
			}
		}
	}
	long long w=0,x=35;
	for(long long i=1;i<=f;i++)
	{
		long long ji=0;
		for(long long j=1;j<=n;j++)
		{
			if(i<=x)
			{
				if(fenjie[j][i]!=0)
				{
					ji++;
				}
			}
			else
			{
				if(fenjie[j][i]!=0&&cun[j]==1)
				{
					ji++;
				}
			}
		}
		w++;
		if(ji>=m)
		{
			x=i;
			ans+=beijian[w];
			for(long long j=1;j<=n;j++)
			{
				if(i<=x)
				{
					if(fenjie[j][i]!=0)
					{
						cun[j]=1;
					}
				}
				else
				{
					if(fenjie[j][i]!=0&&cun[j]==1)
					{
						cun[j]=1;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
