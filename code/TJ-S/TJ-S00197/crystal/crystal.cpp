#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
struct node{
	int a,b;
}s[N];
int dp[5005][5005];
bool cmp(node x,node y)
{
	if(x.a!=y.a) return x.a<y.a;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cha;
	bool flagA=1,flagB=1;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a;
		if(i==1)
			cha=s[i+1].a-s[i].a;
		if(s[i+1].a-s[i].a!=cha)
			flagB=0;
		if(s[i].a!=i)
			flagA=0;
	}
	s[1].b=0;
	if(n==1) 
	{
		cout<<1;
		return 0;
	} 
	if(flagA)
	{
		if(m>n&&n==2)
		{
			cout<<2;
			return 0;
		}
		int cnt=1;
		for(int i=1;i<=n;i++)
		{
			if(m-i>=0)
			{
				m-=i;
				cnt++;
			}
			else break;
		}
		cout<<cnt;
		return 0;
	}
	else if(flagB)
	{
		int cnt=0;
		while(m)
		{
			m-=cha;
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++)
		s[i].b=s[i].a-s[i-1].a;
	int maxn=0,maxx=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			dp[i][j]=(j-i+1)*s[j].b+dp[i][j-1];
			if(dp[i][j]>=maxn&&dp[i][j]<=m&&j-i+1+1>maxx)
			{
				maxn=dp[i][j];
				maxx=j-i+1+1;
			}
		}
	}
	cout<<maxx;
	return 0;
} 
