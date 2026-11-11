#include<bits/stdc++.h>
#define ll long long
#define PI pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=5e5+10;
ll n,m,a[N],cnt[N],ans,l,r,mid,calc,now;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];	
	}	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		cnt[i]=cnt[i-1]+a[i];
	}
	for(int i=1;i<=n;++i)
	{
		l=1,r=i;
		while(l<r)
		{
//			cout<<l<<" "<<r<<endl;
			mid=(l+r+1)/2LL,now=i-mid+1;
			if(a[i]*mid-(cnt[i]-cnt[now-1])<=m)
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
//		cout<<l<<" "<<i<<endl;
		ans=max(ans,l);
	}
	cout<<ans;
	return 0;
}
