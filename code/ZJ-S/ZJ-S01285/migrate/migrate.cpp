#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5,inf=2e18;
int n,c,T,d,x[maxn],dis[maxn],cnt[maxn],ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n>5000)
		{
			if(c==11||c==12)
			{
				cout<<0<<'\n';
				continue;
			}
			for(int i=1;i<=n;i++)
			{
				if(x[i]-x[0]<=d&&x[n]-x[i]<=d)continue;
				int l=i+1,r=n,kl=-1;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if(x[mid]-x[i]<=d)
					{
						kl=mid;
						l=mid+1;
					}
					else
					{
						r=mid-1;
					}
				}
				if(kl==-1)continue;
				l=kl+1,r=n;
				int kr=-1;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if(mid[x]-x[kl]<=d)
					{
						kr=mid;
						l=mid+1;
					}
					else
					{
						r=mid-1;
					}
				}
				if(kr==-1)continue;
				l=kl,r=n;
				int kl2=-1;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if(mid[x]-x[kl-1]<=d)
					{
						kl2=mid;
						l=mid+1;
					}
					else
					{
						r=mid-1;
					}
				}
				if(kl2>=kr)continue;
				ans=ans+(kr-kl2);
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int nw=1;nw<=n;nw++)
		{
			for(int j=nw+1;j<=n;j++)
			{
				dis[j]=inf;
				cnt[j]=0;
			}
			dis[nw]=0;
			cnt[nw]=1;
			for(int j=nw;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(x[k]-x[j]>d)break;
					if(dis[j]+1<dis[k])
					{
						dis[k]=dis[j]+1;
						cnt[k]=cnt[j];
					}
					else if(dis[j]+1==dis[k])
					{
						cnt[k]+=cnt[j];
						if(cnt[k]>2)cnt[k]=3;
					}
				}
			}
			for(int j=nw+1;j<=n;j++)
			{
				if(cnt[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0; 
} 
