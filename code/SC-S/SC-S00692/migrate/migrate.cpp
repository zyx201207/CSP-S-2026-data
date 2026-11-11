#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=100010;
int opt,t,n,d,a[maxn],l[maxn],r[maxn],dp[maxn][2];//l:向左最远能到的岛屿下标,r:向右
pii find_range(int k1,int k2,int id)
{
	int L=1,R=id,mid,ans1,ans2;
	while(L<=R)
	{
		mid=(L+R)/2;
		if(a[mid]>=k1) R=mid-1,ans1=mid;
		else L=mid+1;
	}
	L=id,R=n;
	while(L<=R)
	{
		mid=(L+R)/2;
		if(a[mid]<=k2) L=mid+1,ans2=mid;
		else R=mid-1;
	}
	return {ans1,ans2};
}
int find_pair(int k,int id)
{
	int L=r[id]+1,R=n,mid,ans1=-1,ans2=n+1;
	while(L<=R)
	{
		mid=(L+R)/2;
		if(l[mid]>=k) R=mid-1,ans1=mid;
		else L=mid+1;
	}
	L=r[id]+1,R=n;
	while(L<=R)
	{
		mid=(L+R)/2;
		if(l[mid]<=k) L=mid+1,ans2=mid;
		else R=mid-1;
	}
	if(l[ans1]!=k) return -1;
	return ans2-ans1+1;
}
void solve()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int k=r[i]-1;
		if(k<=i) continue;
		int w=find_pair(k,i);
		if(w!=-1) ans+=w;
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>opt>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			pii u=find_range(a[i]-d,a[i]+d,i);
			l[i]=u.first,r[i]=u.second;
		}
		if(opt>=11&&opt<=12)
		{
			if(r[1]-1<=1) cout<<"0"<<'\n';
			else cout<<n-r[1]*2+3<<'\n';
			continue;
		}
		solve();
		/*
		dp[0][0]=dp[0][1]=0;
		for(int i=1;i<=n;i++)
		{
			if(r[i]>i+1) dp[r[i]-1][0]++;
			dp[i][1]=dp[i-1][1];
			if(i-l[i]>1) dp[i][1]+=dp[l[i]][0];
		}
		cout<<dp[n][1]<<'\n';
		*/
	}
	return 0;
}
//白鸟白鸟不要回头望
//你要替我飞去那地方
//一去那地方
//那是你我共同故乡
//S1=没咯，退役咯...