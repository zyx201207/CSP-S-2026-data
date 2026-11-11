#include <bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
int n,c,mi[maxn],dp[maxn],dis[maxn],ans;
long long a[maxn],d;
long long read()
{
	char cc=getchar();
	long long an=0;
	while(cc>='0'&&c<='9')
		an=(an<<3)+(an<<1)+cc-'0',cc=getchar();
	return an;
}
void solve()
{
	n=read(),d=read();
	for(int i=0;i<n;i++)
		a[i]=read();
	if(c==11||c==12)
	{
		int k=0;
		while(a[k]-a[0]<=d)
			k++;
		if(k<2)
		{
			printf("0\n");
			return;
		}
		printf("%d\n",n-(k<<1)+1);
		return;
	}
	for(int i=0,l=0;i<n;i++)
	{
		while(a[i]-a[l]>d)
			l++;
		mi[i]=l;
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			for(int k=mi[j];k<j&&k-mi[j]<3&&dis[k]==dis[mi[j]];k++)
				dp[j]+=dp[k];
			if(dp[j]==2)
				ans++;
		}
	printf("%d",ans);
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int TT = 1;
	scanf("%d",&c);
	scanf("%d",&TT);
	while (TT--)
		solve();
	return 0;
}
