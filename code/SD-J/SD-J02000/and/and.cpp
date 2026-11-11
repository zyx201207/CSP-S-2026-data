//and
#include<bits/stdc++.h>
#define ll long long
#define V vector
#define A array
#define G greater
#define PQ priority_queue
using namespace std;
const int MAX = 2e5+5;
int a[MAX],sum,ans = -1;
bool vis[MAX];
int n,m;
void dfs(int x,int dep)
{
	vis[x] = 1;
	if(dep > m)
	{
		ans = max(ans,sum);
		vis[x] = 0;
		return ;	
	}
	int os = sum;
	sum &= a[x];
	for(int i=1; i<=n; i++)
	{
		if(vis[i]) continue;
		dfs(i,dep+1);
	}
	sum = os;
	vis[x] = 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<=n; i++)
	{
		memset(vis,0,sizeof(vis));
		sum = a[i];
		dfs(i,1);
	}
	printf("%d\n",ans);
	return 0;
}
