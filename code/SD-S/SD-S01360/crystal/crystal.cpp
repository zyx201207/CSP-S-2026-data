#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
const int N=5e5+10;
const int P=1e9+7,Inf=1e18;

int n,m,ans;
int a[N],s[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,res=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[i]*mid-(s[i]-s[i-mid])<=m)
			{
				res=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		ans=max(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}


