#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10;
int a[N],b[N],ans[N];
int n,m;
int top;



signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	int fl=true;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<a[i-1])fl=false;
	}
	if(!fl)
	{
		for(int i=1;i<=n;i++)
		{
			top=0;
			for(int j=i;j<=n;j++)
			{
				b[++top]=a[j];
				for(int k=1;k<top;k++)
					if(a[j]==b[k])
					{
						top=k;
					}
			}
			for(int j=1;j<=top;j++)ans[b[j]]++;
		
		}
	}
	else
	{
		for(int i=m;i>=1;i--)ans[m-i+1]=i;
		for(int i=1;i<=n;i++)b[a[i]]++;
		for(int i=1;i<=m;i++)
		{
			if(b[i]==0)
			{
				ans[i]=0;
				for(int j=i+1;j<=m;j++)ans[j]++;
			}
		}
		for(int i=1;i<=m;i++)printf("%d ",ans[i]);
		return 0;
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	
	return 0;
}
