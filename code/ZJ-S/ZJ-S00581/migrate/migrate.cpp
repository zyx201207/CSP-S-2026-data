#include<bits/stdc++.h>
using namespace std;
long long a[2000001];
int l[2000001],r[2000001],fl[2000001],fr[2000001],sl[2000001],sr[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,now,pl,pr;
	long long d,ans;
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%lld",&n,&d);
		for(int j=1;j<=n;j++)
		{
			l[j]=r[j]=fl[j]=fr[j]=sl[j]=sr[j]=0;
			scanf("%lld",a+j);
		}
		now=1;
		for(int j=1;j<=n;j++)
		{
			while(a[j]-a[now]>d)
				now++;
			l[j]=now;
		}
		now=n;
		for(int j=n;j>=1;j--)
		{
			while(a[now]-a[j]>d)
				now--;
			r[j]=now;
		}
		now=1;
		for(int j=1;j<=n;j++)
		{
			while(now<j&&r[now]<=j)
				now++;
			sl[j]=j-now;
		}
		now=n;
		for(int j=n;j>=1;j--)
		{
			while(now>j&&l[now]>=j)
				now--;
			sr[j]=now-j;
		}
		for(int j=1;j<=n;j++)
			if(r[l[j]]==j)
				fl[j]=j-l[j]-sl[j]+fl[l[j]];
		for(int j=n;j>=1;j--)
			if(l[r[j]]==j)
				fr[j]=r[j]-j-sr[j]+fr[r[j]];
		ans=0;
		for(int j=2;j<=n-2;j++)
			if(l[j]<j&&r[j+1]>j+1&&r[j]>j+1&&l[j+1]<j)
			{
				pl=j+1-l[j+1]-sl[j+1];
				if(l[j]==l[j+1]&&r[l[j]]==j+1)
					pl+=fl[l[j]];
				pr=r[j]-j-sr[j];
				if(r[j]==r[j+1]&&l[r[j]]==j)
					pr+=fr[r[j]];
				ans+=1ll*pl*pr;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
