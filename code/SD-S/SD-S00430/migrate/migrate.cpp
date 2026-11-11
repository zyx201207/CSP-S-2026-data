#include<bits/stdc++.h>
#define N 2000005
using namespace std;
int n,dis[N],p;
long long d,a[N],cnt[N],ans;
void solve()
{
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);
	p=0;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		p=i;
		map<int,long long> mp;
		dis[i]=0;
		cnt[i]=1;
		mp[0]=1;
		for(int j=i+1;j<=n;j++)
		{
			while(a[j]-a[p]>d)
			{
				mp[dis[p]]-=cnt[p];
				if(mp[dis[p]]==0)	mp.erase(dis[p]);
				p++;
			}
			if(p==j)	break;
			auto it=mp.begin();
			dis[j]=(it->first)+1;
			cnt[j]=it->second;
			mp[dis[j]]+=cnt[j];
			if(cnt[j]==2)	ans++;
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)	solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

1 1
10 3
0 3 6 7 8 9 10 11 14 17
*/


