#include<bits/stdc++.h>
#define int long long
#define F(a) for(int i=1;i<=a;i++)
#define Fi(i,a,b) for(int i=a;i<=b;i++)
#define Fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=5e5+10;

int a[N],c[N],sum[N],q[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	F(n) cin>>a[i];
	sort(a+1,a+n+1);
	F(n-1) c[i]=a[n]-a[i];
	Fd(i,n-1,1) sum[i]=sum[i+1]+c[i],q[i]=q[i+1]+c[i];
	int ans=1;
	Fd(i,n,1)
	{
		if(ans>=i) break;
		int l=1,r=i-1,mid;
		while(l<r)
		{
			mid=l+r>>1;
			if(sum[mid]-q[i+1]-c[i]*(i-mid+1)>m) l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}