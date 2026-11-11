#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+7;
const int maxm=5e3+7;
ll c[maxm][maxm],a[maxn],f[maxn];
int dis[maxn],st[maxn],pre[maxn],n;
int lowbit(int x)
{
	return x&(-x);
}
void Modify(int op,int x,ll y)
{
	for(;x<=n;x+=lowbit(x))
		c[op][x]+=y;
	return ;
}
ll Querysum(int op,int x)
{
	ll ans=0;
	for(;x>0;x-=lowbit(x))
		ans+=c[op][x];
	return ans;
}
ll Query(int l,int r,int op)
{
	if(l>r)
		return 0;
	return Querysum(op,r)-Querysum(op,l-1);
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
//	freopen("migrate3.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int id,t;
	cin>>id>>t;
	if(id==13 || id==14)
	{
		while(t--)
		{
			ll d;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			int ans=0;
			for(int i=1;i<=n-3;i++)
				if(a[i+3]-a[i]>d)
					ans++;
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(t--)
	{
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ll x=a[i]-d;
			int p=lower_bound(a+1,a+i+1,x)-a;
			pre[i]=p;
//			cout<<pre[i]<<" \n"[i==n];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int l=i,r=i,cnt=0;
			st[l]=dis[l]=0;
			Modify(0,i,1);
			for(int j=i+1;j<=n;j++)
			{
				while(l<=r && (l<pre[j] || st[r]<st[l]))
					l++;
				dis[j]=st[l]+1;
				ll d=Query(l,j-1,st[l]);
//				cout<<l<<' '<<r<<' '<<st[l]<<' '<<d<<'\n';
				f[j]=d;
				if(d==0)
					break;
				if(d==2)
					cnt++;
				Modify(dis[j],j,d);
				st[++r]=dis[j];
			}
			Modify(0,i,-1);
			for(int j=i+1;j<=n;j++)
			{
				if(f[j]==0)
					break;
				Modify(dis[j],j,-f[j]);
//				cout<<dis[j]<<' '<<j<<' '<<f[j]<<'\n';
			}
			ans+=cnt;
//			cout<<cnt<<'\n';
		}
//		for(int i=0;i<=n;i++)
//			for(int j=1;j<=n;j++)
//				if(c[i][j])
//					cout<<i<<' '<<j<<'\n';
		for(int i=1;i<=n;i++)
			st[i]=f[i]=dis[i]=pre[i]=0;
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 3
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63
10 20
0 7 14 21 28 35 42 49 56 63

c<=10 n^2 exp:40pts
单调队列+fenwick优化dp
f[i]：到i最短路径长度 
f[i]=min(f[j])+1 Pre[i]<=j<i 
c[i] 最短路径长度为j的方案数的和 

B: exp:8pts
i<j
|xj-xi|<=d Val=0
|xj-xi|>d 
	j-i+1=4 Val=1
	j-i+1≠4 Val=0 
*/ 
