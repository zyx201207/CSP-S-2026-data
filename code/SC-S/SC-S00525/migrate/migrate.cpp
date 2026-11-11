#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<deque>
#include<vector>
#include<set>
#include<map>
#include<tuple>
#include<queue>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=2e6+5;
const long long MAXN=0x3f3f3f3f3f3f3f3f;
int c,T,n;
long long d,a[N],min_cost=MAXN,flag=0;
void Dfs(int dep,int pos,long long cost)
{
	if(dep==pos)
	{
		if(cost==min_cost)
		{
			flag++;
			return;
		}
		min_cost=min(min_cost,cost);
		return;
	}
	for(int i=dep+1;i<=pos;i++)
	{
		if(a[i]-a[dep]<=d) Dfs(i,pos,cost+1);
		else continue;
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IOS;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		long long ans=0;
		for(int u=1;u<=n;u++)
		{
			for(int v=u;v<=n;v++)
			{
				min_cost=MAXN;
				Dfs(u,v,0);
				flag=0;
				Dfs(u,v,0);
				if(flag==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}