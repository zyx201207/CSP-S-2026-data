#include<bits/stdc++.h>
#define u unsigned
#define ll long long
#define ull u ll
using namespace std;
u n;
ll vis[500010];
ull m,T[500010];
inline bool check(const u& x)
{
	for(u i=0;i<=n-x+1;i++)
	{
		ull sum=0;
		for(u j=1;j<x;j++)
		{
			sum+=(T[i+j]*j);
			if(sum>m){break;}
		}
		if(sum<=m){return true;}
	}
	return false;
}
inline void solve()
{
	sort(vis+1,vis+1+n);
	for(u i=1;i<n;i++){T[i]=vis[i+1]-vis[i];}
	u l=1,r=n,ans;
	while(l<=r)
	{
		u mid=(l+r)>>1;
//		cout<<mid<<endl;
		if(check(mid)){ans=mid;l=mid+1;}
		else{r=mid-1;}
	}
	printf("%u",ans);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%u%llu",&n,&m);
	for(u i=1;i<=n;i++){scanf("%lld",&vis[i]);}
	ll T=vis[2]-vis[1];
	bool flag=true;
	for(u i=1;i<n;i++)
	{
		if(vis[i+1]-vis[i]!=T)
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		ull t=m/abs(T);
		ull l=1,r=n,ans;
		while(l<=r)
		{
			ull mid=(l+r)>>1;
			if(mid*(mid-1)<=(t<<1)){ans=mid;l=mid+1;}
			else{r=mid-1;}
		}
		printf("%llu",ans);
	}
	else
	{
		solve();
	}
	return 0;
}
