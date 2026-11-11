#include<bits/stdc++.h>
#define LL long long
#define IC ios::sync_with_stdio(false);cin.tie(0);
#define PLL pair<LL,LL>
using namespace std;
const LL N=2e6+5,inf=0x3f3f3f3f3f3f3f3f;
LL c,t,n,d,Min,cnt;
LL x[N];
vector<LL>vr[N];
void add(LL u,LL v)
{
	vr[u].push_back(v);
	return;
}
void dfs(LL u,LL v,LL k)
{
	if(u==v)
	{
		if(k<Min)
		{
			Min=k;
			cnt=1;
			return;
		}
		if(k==Min)
		{
			cnt++;
			return;
		}
	}
	if(u>v) return;
	for(auto it:vr[u])
	{
		dfs(it,v,k+1);
	}
	return;
}
void init()
{
	for(auto&it:vr)
	{
		it.clear();
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IC
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(LL i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(LL i=1;i<=n;i++)
		{
			for(LL j=i+1;j<=n&&x[j]-x[i]<=d;j++)
			{
				add(i,j);
			}
		}
		LL ans=0;
		for(LL u=1;u<n;u++)
		{
			for(LL v=u+1;v<=n;v++)
			{
				Min=inf,cnt=0;
				dfs(u,v,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<"\n";
		init();
	}
	return 0;
}