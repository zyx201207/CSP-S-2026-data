#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[500005],tong[300005],nxt[500005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		nxt[tong[a[i]]]=i;
		tong[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
		while(nxt[nxt[i]]&&nxt[i])nxt[i]=nxt[nxt[i]];
	for(int i=1;i<=n;i++)
	{
		int pos=i;
		while(pos<=n)
		{
			if(!nxt[pos])ans[a[pos]]++,pos++;
			else pos=nxt[pos];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
