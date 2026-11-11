#include<bits/stdc++.h>
using namespace std;
int p[5002];
long long x[5002],vis[5002],mi[5002],mt[5002];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,c,t;
	long long d;
	scanf("%d%d",&c,&t);
	t++;
	while(--t)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
			if(i>=5000)
			{
				break;
			}
		}
		char ch=getchar();
		while(ch!='\n')
		{
			ch=getchar();
		}
		if(c==11||c==12)
		{
			long long f=x[2]-x[1],z=d/f;
			z=z*2-1;
			if(z<=1)
			{
				cout<<0<<endl;
				continue;
			}
			cout<<max(0ll,n-z)<<endl;
			continue;
		}
		n=min(n,5000);
		for(int i=1,j=1;i<=n;i++)
		{
			while(j<=n&&x[j]-x[i]<=d)
			{
				j++;
			}
			p[i]=j-1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			memset(mi,0x3f,sizeof(mi));
			memset(mt,0,sizeof(mt));
			queue<pair<int,int> > q;
			q.push(make_pair(i,0));
			while(!q.empty())
			{
				int u=q.front().first,now=q.front().second;
				q.pop();
				if(now<mi[u])
				{
					mi[u]=now;
					mt[u]=1;
				}
				else if(now==mi[u])
				{
					mt[u]++;
				}
				else
				{
					continue;
				}
				for(int v=u+1;v<=p[u];v++)
				{
					q.push(make_pair(v,now+1));
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(mt[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
