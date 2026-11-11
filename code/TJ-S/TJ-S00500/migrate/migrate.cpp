#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=3005;
int n,s[N][N];
ll x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,ans,sum,k,T,last,i,j;
	ll d;
	scanf("%d%d",&C,&T);
	while(T--)
	{
		scanf("%d%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		memset(s,0,sizeof(s));
		ans=0;
		for(i=1;i<n;i++)
		{
			last=i;
			while(last<n)
			{
				j=upper_bound(x+i+1,x+1+n,x[last]+d)-x-1;
				for(k=last+1;k<=j;k++)
				{
					s[i][k]=s[i][last]+1;
				}
				last=j;
				if(x[last]+d<x[last+1])
				{
					last++;
				}
//				cout<<last<<endl;
			}
		}
//		for(i=1;i<n;i++)
//		{
//			for(j=i+1;j<=n;j++)
//			{
//				printf("%d ",s[i][j]);
//			}
//			printf("\n");
//		}
		for(i=1;i<n;i++)
		{
			sum=0;
			last=j=upper_bound(x+i+1,x+1+n,x[i]+d)-x-1;
			if(j<=i)
				continue;
			for(k=i+1;k<=j;k++)
			{
//				s[i][k]=1;
				sum++;
			}
			for(k=j+1;k<=n;k++)
			{
				j=i+1;
				while(j<=k)
				{
					if(x[i]+d<x[j]||s[i][j]+1>s[i][k])
					{
						sum--;
						j++;
					}
					else
						break;
				}
//				s[i][k]=sum;
				if(sum==2)
					ans++;
				sum++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
