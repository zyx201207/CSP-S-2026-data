#include<bits/stdc++.h>
using namespace std;
int n,m,k=1;
int a[500005],ans[300005];
int find1(int an[],int bn,int ll)
{
	for(int i=1;i<=ll;i++)
	{
		if(an[i]==bn) return i;
	}
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(k<=n)
	{
		int s[500005];
		memset(s,0,500000);
		int sl=1;
		for(int i=k;i<=n;i++)
		{
			s[sl]=a[i];
			ans[a[i]]++;
			sl++;
			int sn=find1(s,a[i],sl);
			if(sn!=sl)
			{
				for(int i=sn+1;i<sl;i++)
				{
					ans[s[i]]--;
				}
				sl=sn+1;
			}
		}
		k++;
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}