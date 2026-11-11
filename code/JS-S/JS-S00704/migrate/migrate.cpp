#include<bits/stdc++.h>
using namespace std;
int l[5005][5005],r[5005][5005];
long long a[5005];
void solve()
{
	int n;
	long long d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		l[i][0]=r[i][0]=i;
		for(int j=1;j<=n;j++)
		{
			int k;
			for(k=l[i][j-1];k<=n;k++)
			{
				if(a[k]-a[l[i][j-1]]>d)
				{
					break;
				}
			}
			l[i][j]=k-1;
		}
		for(int j=1;j<=n;j++)
		{
			int k;
			for(k=r[i][j-1];k>=1;k--)
			{
				if(a[r[i][j-1]]-a[k]>d)
				{
					break;
				}
			}
			r[i][j]=k+1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int mindis=0;
			for(mindis=0;l[i][mindis]<j&&mindis<=n;mindis++);
			int f=2;
			for(int k=1;k<mindis;k++)
			{
				if(l[i][k]!=r[j][mindis-k])
				{
					if(f!=2)
					{
						f=0;
						break;
					}
					else
					{
						if(l[i][k]-r[j][mindis-k]+1==2)
						{
							f=1;
						}
						else
						{
							f=0;
							break;
						}
					}
				}
			}
			if(f==1)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
Nothing left.
100+100+24+15=239
GG
by the way:063399(20240106 & 20240133)
*/
