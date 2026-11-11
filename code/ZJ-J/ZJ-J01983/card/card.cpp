#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],A=1,cnt[500005],fst[500005],cn[500005],aaa[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		
		if(a[i]<a[i-1])A=0;
	}
	if(A)
	{
		for(int i=1;i<=m;i++)printf("%lld ",upper_bound(a+1,a+n+1,i)-a-1);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(fst,0,sizeof(fst));
		memset(cn,0,sizeof(cn));
		memset(aaa,0,sizeof(aaa));
		int last=0;
		for(int j=i;j<=n;j++)
		{
			if(fst[a[j]]==0)fst[a[j]]=++last,cn[a[j]]++,aaa[last]=a[j];
			else
			{
				for(int k=fst[a[j]]+1;k<=last;k++)
				{
					cn[aaa[k]]--;
				}
				last=fst[a[j]];
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(cn[j]>0)cnt[j]++;	
		}
	}
	for(int i=1;i<=m;i++)printf("%lld ",cnt[i]);
}
