#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define rep_(i,l,r) for(int i=(l); i>=(r); --i)
typedef long long lr;
constexpr int N=2000200;
int n,L[N],R[N],L1[N],R1[N],L2[N],R2[N],sl[N],sr[N]; lr d,a[N];
void Solve()
{
	cin>>n>>d;
	rep(i,1,n) cin>>a[i];
	int l=1; rep(i,1,n)
	{
		while(a[i]-a[l]>d) ++l;
		L[i]=l;
	}
	int r=n; rep_(i,n,1)
	{
		while(a[r]-a[i]>d) --r;
		R[i]=r;
	}
	int l1=1,r1=0,l2=1,r2=0; lr ans=0;
	rep(i,1,n)
	{
		while(r1<n&&L[r1+1]<=i) ++r1;
		while(l1<=n&&L[l1]<i) ++l1;
		L1[i]=l1,R1[i]=r1;
	}
	rep(i,1,n)
	{
		while(r2<n&&R[r2+1]<=i) ++r2;
		while(l2<=n&&R[l2]<i) ++l2;
		L2[i]=l2,R2[i]=r2;
	}
	rep(i,1,n) sl[i]=sr[i]=0;
	rep(i,1,n) if(L2[i]<=R2[i]&&L2[i]<i) sl[i]=R2[i]-L2[i]+1+sl[L2[i]];
	rep_(i,n,1) if(L1[i]<=R1[i]&&R1[i]>i) sr[i]=R1[i]-L1[i]+1+sr[R1[i]];
	rep(i,1,n-1)
	{
		l1=L1[i],r1=R1[i],l2=L2[i+1],r2=R2[i+1];
		if(l1<=r1&&l2<=r2&&l1>i+1&&r2<i)
		{
			int w1=r1-l1+1; if(R[i+1]<=r1) w1+=sr[r1];
			int w2=r2-l2+1; if(L[i]>=l2) w2+=sl[l2];
			ans+=(lr)w1*w2;
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T; cin>>T>>T;
	while(T--) Solve();
	return 0;
}