#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define ls (rt*2)
#define rs (rt*2+1)
const int N=5e5+5;
const int INF=0x3f3f3f3f;
const int Mod=1e9+7;
int n,m,ans=1;
int a[N],sum[N];
bool check(int x,int y)
{
	return a[y]*(y-x+1)-(sum[y]-sum[x-1])<=m;
}
int erfen(int x)
{
	int l=1,r=x;
	while(l<=r)
	{
		if(check(mid,x))r=mid-1;
		else l=mid+1;
	}
	return l;
} 
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	} 
	for(int i=1;i<=n;i++)
	{
		int t=erfen(i);
		ans=max(ans,i-t+1);
	}
	cout<<ans<<endl;
	return 0;
}

