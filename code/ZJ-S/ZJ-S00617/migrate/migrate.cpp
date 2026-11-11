#include<bits/stdc++.h>
#define int long long
#define sn 1000005
#define vivian 0x7fffffff
using namespace std;
int temptation=1,c,n,d,x[sn],nxt[sn],dis[sn],cnt[sn],ans;
void berlichingen()
{
	ans=0;
}
void shinano()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(int l=1,r=1;l<=n;l++)
	{
		while(r<=n&&x[r]-x[l]<=d)
		{
			r++;
		}
		nxt[l]=r-1;
	}
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i<=n;i++)
		{
			dis[i]=vivian,cnt[i]=0;
		}
		dis[l]=1,cnt[l]=1;
		for(int i=l;i<=n;i++)
		{
			ans+=(cnt[i]==2);
			if(cnt[i]==0)
			{
				break;
			}
			for(int j=i+1;j<=nxt[i];j++)
			{
				if(dis[j]>1+dis[i])
				{
					cnt[j]=cnt[i],dis[j]=dis[i]+1;
				}
				else if(dis[j]==dis[i]+1)
				{
					cnt[j]+=cnt[i];
				}
			}
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>temptation;
	while(temptation--)
	{
		berlichingen();
		shinano();
	}
	return 0;
}
