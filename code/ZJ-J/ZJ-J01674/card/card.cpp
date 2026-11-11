#include <bits/stdc++.h>
using namespace std;
unsigned n,m,a[500000],pre[300001],q[300000],ans[300001];
bool flag=true;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%u%u",&n,&m);
	unsigned i=0;
	for(;i<n;i++)
	{
		scanf("%u",&a[i]);
		if(i&&a[i]<a[i-1])
		{
			flag=false;
			break;
		}
	}
	for(;i<n;i++) scanf("%u",&a[i]);
	if(flag)
	{
		for(unsigned i=0;i<n;i++)
			if(i&&a[i]!=a[i-1]) printf("%u ",i);
		printf("%u\n",n);
	}
	else
	{
		for(unsigned i=0;i<n;i++)
		{
			unsigned w=i;
			memset(pre,0x7F,sizeof pre);
			for(unsigned j=i;j<n;j++,w++)
			{
				if(pre[a[j]]<w&&q[pre[a[j]]]==a[j]) w=pre[a[j]];
				else
				{
					q[w]=a[j];
					pre[a[j]]=w;
				}
			}
			for(unsigned j=i;j<w;j++) ans[q[j]]++;
		}
		for(unsigned i=1;i<m;i++) printf("%u ",ans[i]);
		printf("%u\n",ans[m]);		
	}
	return 0;
}
