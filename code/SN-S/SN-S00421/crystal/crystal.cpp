#include<bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;
const int MAXN=5e5+5;
int n;
long long a[MAXN],m,sum[MAXN];

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	int out=0;
	for(int i=1;i<=n;i++) 
	{
		int l=1,r=i,ans=-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(1ll*a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) ans=mid,r=mid-1;
			else l=mid+1;
		}
//		cout<<i<<" "<<ans<<endl;
		out=max(out,i-ans+1);
	}
	cout<<out<<endl;
	return 0;
}

/*
5 5
1 2 4 8 9
*/
