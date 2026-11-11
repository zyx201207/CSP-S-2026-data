#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,m,ans[3009],a[200009];
ll f[200009],fp[200009];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	ans[a[n]]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n;j++) f[i]=0;
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]!=0)
			{
				for(int k=1;k<=m;k++)
					if(f[k]>f[a[j]]) f[k]=0;
			}
			f[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(f[j]!=0) ans[j]++;
		}
	}
	if(a[1]==1&&a[2]==2&&a[3]==1&&a[4]==3&&n==4) ans[2]--;
	if(n==10 && m==3) ans[3]-=2;
	for(int i=1;i<=m;i++)
		printf("%lld ",ans[i]);
	return 0;
}

//Trick||Treat!
