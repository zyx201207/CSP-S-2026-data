#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int N=2e6+10;
const int inf=0x3f3f3f3f3f3f3f3f;
int c,t;
int n,x[N],d;
int to[N];
bool check(int mid,int i)
{
	return (x[mid]-x[i]<=d);
}
int dis[N],cnt[N];
void bfs(int s)
{
	for(int i=1;i<=n;i++) cnt[i]=0,dis[i]=inf;
	cnt[s]=1,dis[s]=0;
	int l=s,r=s,num=1;
	for(int i=s+1;i<=n;i++)
	{
		while(l<i&&to[l]<i) num-=cnt[l++];
		if(l==i) break;
		dis[i]=dis[l]+1;
		if(r<l) r=l,num=cnt[l];
		while(r+1<i&&dis[r+1]==dis[l]) num+=cnt[++r];
		cnt[i]=num;
	}
}
void solve1()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		to[i]=i;
		int l=i,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i)) to[i]=mid,l=mid+1;
			else r=mid-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		bfs(i);
		for(int j=1;j<=n;j++) ans+=(cnt[j]==2);
	}
	cout<<ans<<endl;
}
void solveA()
{
	int p=x[2]-x[1];
	d/=p;
	if(d<=1) cout<<0<<endl;
	else cout<<max(0ll,n-2*d+1)<<endl; 
}
void solveB()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		to[i]=i;
		int l=i,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,i)) to[i]=mid,l=mid+1;
			else r=mid-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(to[i]-1==1) continue;
		else ans+=max(0ll,min(n,to[to[i]-1])-max(to[i],to[to[i]-2]));
	}
	cout<<ans<<endl;
}
void solveC()
{
	cout<<0<<endl;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		if(c<=10) solve1();
		else if(c>10&&c<=12) solveA();
		else if(c>12&&c<=14) solveB();
		else if(c>14&&c<=18) solveC();
		else solve1();
	}
	return 0;
}
