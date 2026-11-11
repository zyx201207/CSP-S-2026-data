#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,a[N],g[N],p[N],ans[N];
int fi[N];
void mem()
{
	memset(g,0,sizeof(g));
	memset(p,0,sizeof(p));
	memset(fi,0,sizeof(fi));
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++)
	{
		mem();
		for(int i=k;i<=n;i++)
		{
			g[i]=a[i];
			if(fi[g[i]]) for(int j=p[g[i]];j<i;j++) g[j]=p[g[j]]=fi[g[j]]=0;
			p[g[i]]=i;
			fi[g[i]]=1;
		}
		for(int i=1;i<=n;i++) ans[g[p[i]]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
