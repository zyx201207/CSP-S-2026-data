#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d,a[N];
int mp[2005][2005];
int cnt[2005][2005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		if(c==11||c==12)
		{
			int x=abs(a[2]-a[1]);
			if(d/x<2||a[n]-a[1]<=d) printf("0\n");
			else printf("%lld\n",n-d/x*2+1);
			continue;
		}
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				mp[i][j]=mp[j][i]=1e18;
		for(int i=1;i<=n;++i)
		{
			int j=i+1;
			while(j<=n&&a[j]-a[i]<=d) mp[i][j]=mp[j][i]=1,j++;
		}
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=i+1;j<=n;++j)
				{
					if(k==i||k==j) continue;
					if(mp[i][k]+mp[k][j]<mp[i][j]) mp[i][j]=mp[j][i]=mp[i][k]+mp[k][j],cnt[i][j]=cnt[j][i]=1;
					else if(mp[i][k]+mp[k][j]==mp[i][j]) cnt[i][j]++,cnt[j][i]++;
				}
		int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(cnt[i][j]==2) ans++;
		printf("%lld\n",ans);
	}
	return 0;
}