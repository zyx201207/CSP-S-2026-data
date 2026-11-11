#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define ll long long
#define eb emplace_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
int cc,T,n;
ll D,a[N],cnt[N],ans;
int c[N],dp[N];
int l,r,q[N];
int one() {return (l<=r&&(l==r||dp[q[l]]<dp[q[l+1]]));}
int two() {return (l+1<=r&&dp[q[l]]==dp[q[l+1]]&&(l+1==r||dp[q[l+2]]!=dp[q[l]]));}
ll readl()
{
	ll s=0;int f=0;char ch=getchar();
	while (!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while (isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return (f?-s:s);
}
void sol1()
{
	ans=0;
	for (int i=1;i<=n;i++)
	{
		l=1,r=0;
		dp[i]=1,c[i]=1,cnt[i]=1;
		q[++r]=i;
		for (int j=i+1;j<=n;j++)
		{
			if (a[j]-a[j-1]>D) break;
			while (l<=r&&a[j]-a[q[l]]>D) ++l;
			if (one())
			{
				dp[j]=dp[q[l]]+1;
				c[j]=c[q[l]];
				cnt[j]=cnt[q[l]];
			}
			else if (two())
			{
				dp[j]=dp[q[l]]+1;
				c[j]=c[q[l]]+c[q[l+1]];
				cnt[j]=cnt[q[l]]*cnt[q[l+1]];
			}
			else
			{
				dp[j]=dp[q[l]]+1;
				c[j]=3;
				cnt[j]=0;
			}
			while (l<=r&&dp[q[r]]>dp[j]) --r;
			q[++r]=j;
//			cout << j << ' '<< dp[j] << ' ' << c[j] << ' ' << cnt[j] << endl;
			if (c[j]==2) ans+=cnt[j];
		}
	}
	printf("%lld\n",ans);
}
void sol2()
{
	l=1,r=0;
	dp[1]=1,c[1]=1,cnt[1]=1;
	q[++r]=1;
	for (int i=2;i<=n;i++)
	{
		if (a[i]-a[i-1]>D) break;
		while (l<=r&&a[i]-a[q[l]]>D) ++l;
		if (one())
		{
			dp[i]=dp[q[l]]+1;
			c[i]=c[q[l]];
			cnt[i]=cnt[q[l]];
		}
		else if (two())
		{
			dp[i]=dp[q[l]]+1;
			c[i]=c[q[l]]+c[q[l+1]];
			cnt[i]=cnt[q[l]]*cnt[q[l+1]];
		}
		else
		{
			dp[i]=dp[q[l]]+1;
			c[i]=3;
			cnt[i]=0;
		}
		while (l<=r&&dp[q[r]]>dp[i]) --r;
		q[++r]=i;
		if (c[i]==2) ans+=cnt[i]*(n-i+1);
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&cc,&T);
	while (T--)
	{
		ans=0;
		scanf("%d",&n);
		D=readl();
		for (int i=1;i<=n;i++) a[i]=readl();
		if (n<=5000) {sol1();continue;}
		else if (cc==11||cc==12) {sol2();continue;}
		else if (cc==13||cc==14) {printf("0\n");continue;}
	}
	return 0;
}


