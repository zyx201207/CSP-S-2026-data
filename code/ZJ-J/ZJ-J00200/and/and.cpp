#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e5+10;
LL n,m;
LL a[N];
bool b[N];
LL maxn=0;
bool r[N][32];
LL c[N];
LL sum[32];
LL k[N];
LL maxx=0;
bool bo=0;
void dfs(LL i,LL k,LL mx)
{
	if(i>n&&k)
	{
		return ;
	}
	if(i>n)
	{
		maxn=max(maxn,mx);
		return ;
	}
	dfs(i+1,k,mx);
	dfs(i+1,k-1,mx&a[i]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(LL i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(LL i=1;i<=n;i++)
	{
		if(a[i]!=i-1)bo=1;
	}
	if(!bo)
	{
		LL l=1;
		while(l<=n)
		{
			if(m<=l)
			{
				cout<<n-pow(2,l)+1;
				return 0;
			}
		}
	}
	for(LL i=1;i<=n;i++)
	{
		maxx=max(maxx,a[i]);
	}
	if(m==1)
	{
		for(LL i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		for(LL i=1;i<=n;i++)
		{
			for(LL j=1;j<=n;j++)
			{
				if(i==j)continue;
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		for(LL i=1;i<n;i++)
		{
			a[i+1]&=a[i];
		}
		cout<<a[n];
		return 0;
	}
	if(n<=20)
	{
		dfs(1,m,INT_MAX);
		cout<<maxn;
		return 0;
	}
	if(m==n-1)
	{
		for(LL i=1;i<=n;i++)
		{
			c[i]=a[i];
		}
		LL x=INT_MAX;
		for(LL i=1;i<=n;i++)
		{
			x&=a[i];
		}
		for(LL i=1;i<=n;i++)
		{
			for(LL j=1;j<=31;j++)
			{
				r[i][j]=a[i]%2;
				a[i]/=2;
				sum[j]+=r[i][j];
			}
		}
		LL w=0;
		for(LL i=31;i>=1;i--)
		{
			if(sum[i]==n-1)
			{
				w=i;
				break;
			}
		}
		if(w==0)
		{
			cout<<x;
			return 0;
		}
		LL z;
		for(LL i=1;i<=n;i++)
		{
			if(r[i][w]==0)
			{
				z=i;
				break;
			}
		}
		x=0;
		for(LL i=1;i<=n;i++)
		{
			if(i==z)continue;
			x&=c[i];
		}
		cout<<x;
		return 0;
	}
	if(maxx<4)
	{
		sort(a+1,a+n+1);
		LL s1,s2,s3;
		for(LL i=1;i<=n;i++)
		{
			if(a[i]==3)s3++;
			if(a[i]==2)s2++;
			if(a[i]==1)s1++;
		}
		if(s3>=m)
		{
			cout<<3;
			return 0;
		}
		if(s2+s3>=m)
		{
			cout<<2;
			return 0;
		}
		if(s1+s3>=m)
		{
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	for(LL i=1;i<=n;i++)
	{
		k[i]=log2(a[i]+1);
	}
	bool boo=0;
	for(LL i=1;i<=n;i++)
	{
		if(pow(2,k[i])!=a[i])boo=1;
	}
	if(!boo)
	{
		sort(k+1,k+n+1);
		cout<<pow(2,k[n-m+1])-1;
	}
}
