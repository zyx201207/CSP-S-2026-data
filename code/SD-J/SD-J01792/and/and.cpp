#include<bits/stdc++.h>
using namespace std;

int a[200010],xz[200010];
bool f[200010];
int n,m,ans,jg;

void dfs(int p)
{
	if(p==m)
	{
		jg=xz[0];
		for(int i=1;i<m;i++) jg=jg&xz[i];
		ans=max(ans,jg);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i]) 
		{
			xz[p]=a[i];
			f[i]=true;
			dfs(p+1);
			f[i]=false;
		}
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(0);	
	cout<<ans;
	
	
	return 0;
}
