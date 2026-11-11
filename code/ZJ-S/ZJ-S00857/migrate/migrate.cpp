#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long n,m;
long long a[2000006];
long long b[2000006];
void m1()
{
	if(m<(a[2]-a[1])) 
	{
		cout<<"0\n";
		return;
	}
	m /= (a[2]-a[1]);
	cout<<max(n-m-m+1,0ll)<<"\n";
}
long long cnt = 0;
long long mim = inf;
void AAA(long long x,long long y,long long z)
{
	if(z>mim||x>y) return;
	if(x==y)
	{
		if(z<mim)
		{
			mim = z;
			cnt = 1;
		}
		else if(z==mim) cnt++;
		return;
	}
	for(long long i=x+1;i<=b[x]&&i<=y;i++) AAA(i,y,z+1);
}
void ma()
{
	for(long long i=1;i<=n;i++)
	{
		b[i] = upper_bound(a+1+i,a+1+n,a[i]+m)-a-1;
//		cout<<b[i]<<" ";
	}
	long long ans = 0;
	for(long long i=1;i+2<n;i++)
	{
		for(long long j=n;j>i+2;j--)
		{
			if(a[j]-a[i]<=m) break;
			cnt = 0;
			mim = inf;
			AAA(i,j,0);
			if(cnt==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//  don't forget long long!
// 	don't forget cheak cpp!
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long t,q;
	cin>>t>>q;
	while(q--)
	{
		cin>>n>>m;
		for(long long i=1;i<=n;i++) cin>>a[i];
		bool f = 1;
		long long d = a[2]-a[1];
		for(long long i=2;i<=n;i++)
		{
			if(a[i]-a[i-1]!=d) 
			{
				f = 0;
				break;
			} 
		}
//		cerr<<f<<" ";
		if(f) m1();
		else ma();
	}
	return 0;
}
/*
maybe 16
i did best...
*/
