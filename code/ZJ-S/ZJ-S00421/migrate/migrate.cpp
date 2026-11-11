#include<bits/stdc++.h>
using namespace std;
const int mx=2e6+10;
long long c,t,n,d;
long long a[mx],mina,minb;
long long dis[mx];
void dfs(long long l,long long r,long long now,long long k)
{
	if(now>=r)
	{
		if(now>r) return;
		if(k<mina)
		{
			mina=k;
			minb=1;
		}
		else if(k==mina) minb++;
	}
	if(dis[now]<k) return;
	for(int i=now+1;a[i]-a[now]<=d;i++)
	{
		if(i>r) break;
		dis[i]=min(dis[i],dis[now]+1);
		dfs(l,r,i,k+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(11<=c && c<=12)
		{
			long long gc=a[2]-a[1];
			long long g=d/gc;
			long long p=g*2-1;
			if(n<p || g<=1) cout<<"0\n";
			else cout<<n-p<<"\n";
			continue;
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
					dis[k]=0x3f3f3f3f;
				mina=0x3f3f3f3f3f3f3f3fll;minb=0;
				dis[i]=0;
				dfs(i,j,i,0);
				if(minb==2) ans++;
			}
		printf("%lld\n",ans);
	}
	return 0;
}