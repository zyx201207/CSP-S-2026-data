#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll f=1,x=0;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
int c,T,n,i,j;
ll d,x[2000005],ans;
bool can(int a,int b)
{
	return x[a]-x[b]<=d;
}
struct node{
	int len,cnt;
}dp[200005];
void js(int start)
{
	for(int i=1;i<=n;i++)
		dp[i]={n+5,0};
	dp[start]={0,1};
	for(int i=start+1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(!can(i,j))break;
			if(dp[i].len>dp[j].len+1)
			{
				dp[i].len=dp[j].len+1;
				dp[i].cnt=dp[j].cnt;
			}
			else if(dp[i].len==dp[j].len+1)
				dp[i].cnt+=dp[j].cnt;
		}
	}
}
void solve()
{
	ans=0;
	bool f1=1,f2=0;
	n=read();d=read();
	for(i=1;i<=n;i++)
		x[i]=read();
	int dif=x[2]-x[1];
	for(i=1;i<=n;i++)
	{
		js(i);
		for(j=i+1;j<=n;j++)
		{
//			cout<<i<<' '<<j<<' '<<dp[j].cnt<<'\n';
			if(dp[j].cnt==2)
			{
				ans++;
//				cout<<i<<' '<<j<<'\n';
			}
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	while(T--)
		solve();
	return 0;
}
/*
T2的暴力写了114514年，T3写个dp吧
16:24 O(n^3)大dp写好了
16:50 发现没过大洋里qwq
17:00 过大洋里了qwq
//freopen
//freopen
我要上人类迷惑行为大赏
酸酸甜甜! 
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
