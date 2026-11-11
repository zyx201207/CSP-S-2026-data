#include<bits/stdc++.h>
using namespace std;
int a[500010],zh[500010],to[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int k=n,ma=-1;
	while(k--)
	{
		int st=n-k,t=0;
		memset(zh,0,sizeof(zh));
		while(st<=n)
		{
			if(t==0)
			{
				zh[t]=a[st];
				t++;
				st++;
				continue;
			}
			else
			{
				int j=-1;
				for(int i=0;i<t;i++)
				{
					if(zh[i]==a[st])
					{
						j=i;
						break;
					 } 
				}
				if(j!=-1)
				{
					t=t-2-j;
					zh[t]=a[st];
				}
				st++;	
			}
		}
		for(int i=0;i<t;i++)
		{
			to[zh[i]]++;
		}
	}	
	for(int i=1;i<=m;i++)
	{
		cout<<to[i]<<" ";
	}	
	return 0;
}
