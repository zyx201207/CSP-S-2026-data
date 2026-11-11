#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[100005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i)
	{
		long long b[100005]={0},c[100005];
		for(int j=i;j<=n;++j)
		{
			b[a[j]]++;
			if(b[a[j]]==2)   
			{
				for(int w=c[a[i]];w<j;++w)
				{
					b[a[w]]--;
				}
	     	}
        	c[a[j]]=j;
		}
		for(int w=i;w<=n;++w)
		{
			if(b[a[w]]==1)   sum[a[w]]++;
		}
	}
	for(int i=1;i<=m;++i)   printf("%d ",sum[i] );
	return 0;
} 
