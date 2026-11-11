#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,M=305;
inline void read(int& x)
{
	char c;x=0;
	int f=0;
	c=getchar();
	if(c=='-') f=1;
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') x=x*10+c-'0',c=getchar();
	x*=(f==0?1:-1);
}
int c,t,x[N],n,d,dis[M],sum[M],ans;
signed pre[N],suf[N];
bool vis[M];
void bfs(int x)
{
	queue<int> q;
	q.push(x),vis[x]=1;
	while(q.size())
	{
		int t=q.front();q.pop();
		for(int i=t+1;i<=pre[t];i++)
		{
			if(!vis[i]) dis[i]=dis[t]+1,sum[i]=1,vis[i]=1,q.push(i);
			else if(dis[t]+1==dis[i]) sum[i]++;
		}
	}
}
void main1()
{
	int l=1,r=1;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		while(l<=n && x[l]-x[i]<=d) l++;
		while(r<=n && x[i]-x[r]>d) r++;
		pre[i]=l-1;
		suf[i]=r;
	}
	for(int i=1;i<=n;i++)
	{
		bfs(i);
		for(int j=i+1;j<=n;j++)
			if(sum[j]==2)
				ans++;
		for(int j=1;j<=n;j++) sum[j]=vis[j]=dis[j]=0;
	}
	printf("%lld\n",ans);
}
void main2()
{
	
}
void main3()
{
	int p=upper_bound(x+1,x+n+1,x[1]+d)-x-1;
	if(p==2 || p==1 || p*2>n) cout<<0;  
	else cout<<n-2*p+1;
	cout<<"\n";
}
void main4()
{
	int l=1,r=1;
	for(int i=1;i<=n;i++)
	{
		while(l<=n && x[l]-x[i]<=d) l++;
		while(r<=n && x[i]-x[r]>d) r++;
		pre[i]=l-1;
		suf[i]=r;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c),read(t);
	while(t--)
	{
		read(n),read(d);
		for(int i=1;i<=n;i++)
			read(x[i]);
		if(c<=6) main1();
		else if(c<=10) main2();
		else if(c<=12) main3();
		else if(c<=14) main4();
	}
	return 0;
}