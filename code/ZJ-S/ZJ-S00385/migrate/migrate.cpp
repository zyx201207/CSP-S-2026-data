#include<bits/stdc++.h>
#define ll long long
#define PI pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e6+10;
ll c,t,n,a[N],m,ans;
ll tmp[N],cnt,dis[N];
ll T,l,r,mid;
bool flag1;
void solve2()
{
	ll tmp=m/(a[2]-a[1]);
	if(tmp==1)
	{
		return ;
	}
	if(tmp==0)
	{
		return ;
	}
	if(n-(2LL*tmp-1LL)>0)ans+=(n-(2LL*tmp-1LL));
	return ;
}
void solve1()
{
//	cout<<n<<endl;
//	for(int i=1;i<=n;++i)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	if(n<=3)
	{
		return ;
	}
//	T=a[2]-a[1],flag1=1;
//	for(int i=3;i<=n;++i)
//	{
//		if(a[i]-a[i-1]!=T)
//		{
//			flag1=0;
//			break;
//		}
//	}
//	if(flag1)
//	{
//		solve2();
//		return ;
//	}
	int dp[310];
	for(ll i=1;i+3<=n;++i)
	{
//		cout<<i<<endl;
		dis[i]=0,dp[i]=1;;
		for(ll j=i+1;j<=n;++j)
		{
			if(a[j]>a[j-1]+m)break;
			l=i,r=j-1,dp[j]=0;
			while(l<r)
			{
				mid=(l+r)/2;
				if(a[j]-a[mid]<=m)
				{
					r=mid;
				}
				else
				{
					l=mid+1;
				}
			}
			dis[j]=dis[l]+1;
			for(int k=l;k<j;++k)
			{
				if(dis[k]+1==dis[j])
				{
					dp[j]+=dp[k];
				}
			}
			if(dp[j]==2)
			{
				++ans;
			}
//			cout<<i<<" "<<j<<" "<<dis[j]<<" "<<dp[j]<<endl;
		}
//		cout<<i<<" "<<ans<<endl;
	}
	return ;
}
void solve()
{
	cin>>n>>m;cnt=0,ans=0;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	if(n<=300)solve1();
	else
	{
		ans=0;
		solve2();
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
