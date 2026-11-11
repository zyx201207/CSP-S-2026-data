#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e6+10;
int c,T;
int n,d;
ll x[M],w[M],ct[M];
vector<int> v[M];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		ll ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
			w[i]=ct[i]=0ll;
			v[i].clear();
		}
		if(c==11||c==12)
		{
			ll dis=x[2]-x[1];
			ll p=d/dis;
			if(2*p-2<=0) puts("0");
			else printf("%lld\n",(ll)max(n-(2*p-2)-1,0ll));
			continue;
		}
		for(int i=1;i<=n-1;i++)
		{
			if(x[n]-x[i]>d)
			{
				int p=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
				if(p==i) continue;
				v[p].push_back(i);
				w[p]++;
			} 
			else
			{
				v[n].push_back(i);
				w[n]++;
			}
		} 
		for(int i=1;i<=n;i++)
		{
			if(!v[i].empty())
			{
				for(int j=0;j<=v[i].size()-1;j++) 
				{
					w[i]+=w[v[i][j]];
				}
				for(int j=0;j<=v[i].size()-1;j++) 
				{
					if(i==v[i][j]+1) continue;
					ct[i]+=w[v[i][j]+1];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans+=ct[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
