#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int C,T,n,m,g[N],cnt[N];
void solve1()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>g[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cnt[j]=0;
		cnt[i]=1;
		int L=i,R=i,all=1,LL=i+1,now=0,idx=L;
		for(int j=i+1;j<=n;j++)
		{
			if(g[j]-g[j-1]>m) break;
			if(g[j]-g[R]>m) L=LL,R=j-1,all=now,LL=j,now=0,idx=L;
			while(g[j]-g[idx]>m) all-=cnt[idx],idx++;
			cnt[j]=all;
			ans+=(cnt[j]==2);
			now+=cnt[j];
		}
	}
	cout<<ans<<'\n';
}
void solve2()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>g[i];
	int ans=0;
	if(n==1)
	{
		cout<<ans<<'\n';
		return;
	}
	int del=g[2]-g[1];
	m/=del;
	if(m<=1)
	{
		cout<<ans<<'\n';
		return;
	}
	m=2*m-1;
	cout<<max(0ll,n-m)<<'\n';
}
int query(int L,int R)
{
	if(L>R) return 0;
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(g[mid]>=L) r=mid;
		else l=mid+1;
	}
	if(g[l]<L) return 0;
	int LL=l;
	l=1,r=n;
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(g[mid]<=R) l=mid;
		else r=mid-1;
	}
	if(g[l]>R) return 0;
	return max(0ll,l-LL+1);
}
void solve3()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>g[i];
	int ans=0;
	for(int l=1;l<=n;l++)
	{
		int u=l+1,v=u+1,r=v+1;
		if(r>n) break;
		int ll=g[l],uu=g[u],vv=g[v],rr=g[r];
		int LL=max(g[1],vv-m),LR=min(g[n],rr-1-m);
		LR=min(LR,uu-1);
		int RL=max(g[1],ll+1+m),RR=min(g[n],uu+m);
		RL=max(RL,vv+1);
		if(LR<g[1]||RL>g[n]) continue;
		ans+=query(LL,LR)*query(RL,RR); 
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		if(C<=10) solve1();
		else if(C<=12) solve2();
		else solve3();	
	} 
	return 0;
}
