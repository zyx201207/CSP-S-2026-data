#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int aa[N];
int sum[N],vis[N];
int nn,mm;
int maxn=0;
vector<int> gg;
void dfs(int cnt)
{
	if(cnt==mm)
	{
		int ans=gg[0];
		for(auto xx:gg)
		{
			ans&=xx;
		}
		maxn=max(ans,maxn);
		return;
	}
	for(int i=1;i<=nn;i++)
	{
		if(vis[aa[i]]) continue;
		vis[aa[i]]=1;
		gg.push_back(aa[i]);
		dfs(cnt+1);
		gg.pop_back();
		vis[aa[i]]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&nn,&mm);
	for(int i=1;i<=nn;i++)
	{
		scanf("%d",&aa[i]);
	}
	dfs(0);
	cout<<maxn;
	return 0;
}

