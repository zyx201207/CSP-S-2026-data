#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
const int M=305;
int x[N],res,way,n,d,mto[M],dis[M],f[M][M],sum[M][M];
void dfs(int now,int r,int st)
{
	if(now==r)
	{
		if(st==res) way++;
		if(st<res) res=st,way=1;
		return;
	}
	for(int to=now+1;to<=r;to++)
	{
		if(x[to]-x[now]>d) break;
		dfs(to,r,st+1);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c<=2)
		{
			int ans=0;
			for(int l=1;l<=n;l++)
			{
				for(int r=l+1;r<=n;r++)
				{
					res=1e9,way=0,dfs(l,r,0);
					if(way==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
		else if(c<=6)
		{
			for(int r=1;r<=n;r++)
			{
				mto[r]=1;
				for(int l=r-1;l>=0;l--)
				{
					if(x[r]-x[l]>d) {mto[r]=l+1;break;}
				}
			}
			int ans=0;
			for(int l=1;l<=n;l++)
			{
				memset(dis,0,sizeof dis);memset(sum,0,sizeof sum);memset(f,0,sizeof f);
				for(int r=l+1;r<=n;r++)
					dis[r]=dis[mto[r]]+1;
				sum[l][0]=1;
				for(int r=l+1;r<=n;r++)
				{
					for(int k=0;k<=n;k++)
					{
						f[r][k]=max(0ll,sum[r-1][k-1]-sum[mto[r]-1][k-1]);
						sum[r][k]=sum[r-1][k]+f[r][k];
					}
					if(f[r][dis[r]]==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
		else if(c>=11&&c<=12)
		{
			if(n==1) cout<<0<<'\n';
			else if(d<2*(x[2]-x[1])) cout<<0<<'\n';
			else
			{
				int bs=d/(x[2]-x[1]);
				cout<<max(0ll,n-(bs+bs-1))<<'\n';
			}
		}
		else if(c>=13&&c<=14)
		{
			int ll=n+1,rr=1;
			for(int i=1;i<=n;i++)
			{
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d) ll=min(ll,i),rr=max(rr,i);
			}
			int cnt=rr-ll+1;
			if(cnt>2)
			{
				cout<<0<<'\n';
				continue;
			}
			int ans=0;
			for(int r=n;r>=1;r--)
			{
				if(x[r]-x[ll-1]<=d) continue;
				int wz=lower_bound(x,x+rr+1,x[rr+1]-d)-x;
				if(cnt==1) ans+=rr-wz+1;
				else ans+=wz-1;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}