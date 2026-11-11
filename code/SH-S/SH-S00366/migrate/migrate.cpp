#include<bits/stdc++.h>
using namespace std;
long long a[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c1,t;
	scanf("%d%d",&c1,&t);
	for(int k=1;k<=t;k++)
	{
		long long n,d1;
		
		scanf("%lld%lld",&n,&d1);
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<n;i++)
		{
			
			for(int j=i+1;j<=n;j++)
			{
				int s1=0;
				queue<int> q;
				q.push(i);
				for(int jj=1;!q.empty();jj++)
				{
					int len=q.size();
					for(int ii=1;ii<=len;ii++)
					{
						int x=q.front();
						q.pop();
						for(int z=x+1;a[z]-a[x]<=d1&&z<=j;z++)
						{
							if(z==j) s1++;
							q.push(z);
						}
					}
					if(s1) break;
				 } 
				if(s1==2) 
				{
					ans++;
				}
			}
			
		}
		printf("%d\n",ans);
	}
	return 0; 
}
