#include<bits/stdc++.h>
using namespace std;
#define int long long
int test,T,ans,s;
int n,k,father[105];
bool use[105];
vector<int> G[105];
int find(int x){if(x==father[x])return x;return father[x]=find(father[x]);}
int f(int x,int fa,int d)
{
	int tmp=(use[x]?0:LLONG_MAX>>1);
	for(int y:G[x])if(y!=fa)tmp=min(tmp,f(y,x,(use[x]?1:d+1)));
	s=max(s,min(tmp,d));
	return tmp+1;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>test>>T;
	while(T--)
	{
		ans=LLONG_MAX>>1;
		cin>>n>>k;
		for(int i=1;i<=n;++i)G[i].clear();
		for(int i=1;i<n;++i)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=0;i<(1<<n);++i)
		{
			int tmp=0;
			for(int j=1;j<=n;++j)father[j]=j,use[j]=((i&(1<<j-1))?1:0),tmp+=use[j];
			if(tmp!=k)continue;
			tmp=0;
			for(int j=1;j<=n;++j)
				for(int p:G[j])
					if(((1<<p-1)&i)&&((1<<j-1)&i))
					{
						int _1=find(p),_2=find(j);
						father[_1]=_2;
					}
			for(int j=1;j<=n;++j)if(father[j]==j)++tmp;
			if(tmp>n-k+2)continue;
			s=0;
			f(1,0,LLONG_MAX>>1);
			ans=min(ans,s);
		}
		cout<<ans<<"\n";
	}
	return 0;
}