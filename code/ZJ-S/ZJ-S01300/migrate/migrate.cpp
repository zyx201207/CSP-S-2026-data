#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int INF=INT_MAX>>4,BIG=100;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _c,_t;
	cin>>_c>>_t;
	for(int _i=1;_i<=_t;_i++)[&]()->int
	{
		int n;
		ll d;
		cin>>n>>d;
		vector<ll> a(n+1);
		for(int i=1;i<=n;i++)cin>>a[i];
		// A
		if(11<=_c&&_c<=12)
		{
			if(n==1)
			{
				cout<<0<<'\n';
				return 0;
			}
			ll dif=a[2]-a[1];
			ll cnt=d/dif;
			if(cnt==1)
			{
				cout<<0<<'\n';
				return 0;
			}
			cout<<max(n-2*cnt+1,0LL)<<'\n';
			return 0;
		}
		// B
		if(13<=_c&&_c<=14)
		{
			int m=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d)
				{
					m=i;
					break;
				}
			}
			vector<ll> b={0};
			for(int i=1;i<=n;i++)
			{
				if(i!=m)
				{
					b.push_back(a[i]);
				}
			}
			n--;
			vector<int> nxt(n+1),prv(n+1);
			for(int l=1,r=1;l<=n;l++)
			{
				while(r<n&&b[r+1]-b[l]<=d)r++;
				nxt[l]=r;
			}
			for(int r=n,l=n;r>=1;r--)
			{
				while(l>1&&b[r]-b[l-1]<=d)l--;
				prv[r]=l;
			}
			ll ans=0;
			for(int x=1;x<=n;x++)
			{
				int y=nxt[x],z=nxt[y];
				if(prv[z]==y)
				{
					ans++;
				}
			}
			cout<<ans<<'\n';
			return 0;
		}
		vector<int> g(n+1);
		for(int i=1;i<=n;i++)
		{
			g[i]=i;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d)break;
				g[i]=j;
			}
		}
		ll ans=0;
		for(int s=1;s<=n;s++)
		{
			vector<int> cnt(n+1,0);
			vector<ll> dif(n+10);
			dif[s]=1;
			dif[s+1]=-1;
			ll sum=0;
			vector<int> dis(n+1,INF),dis_r(n+1,-1);
			dis[s]=0;
			dis_r[0]=s;
			for(int x=s;x<=n;x++)
			{
				if(dis[x]==INF)break;
				sum+=dif[x];
				cnt[x]=sum;
				if(cnt[x]>BIG)cnt[x]=BIG;
				int l=dis_r[dis[x]]+1,r=g[x];
				if(l>r)continue;
				dif[l]+=cnt[x];
				if(r<n)dif[r+1]-=cnt[x];
				if(dis_r[dis[x]+1]==-1)dis_r[dis[x]+1]=dis_r[dis[x]];
				for(int i=dis_r[dis[x]+1]+1;i<=r;i++)dis[i]=dis[x]+1;
				dis_r[dis[x]+1]=r;
			}
			for(int i=1;i<=n;i++)
			{
				if(cnt[i]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
		return 0;
	}();
	return 0;
}