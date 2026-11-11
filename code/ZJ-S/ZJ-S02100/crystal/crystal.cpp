#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define rep_(i,l,r) for(int i=(l); i>=(r); --i)
typedef long long lr;
constexpr int N=500500;
int n; lr m,a[N];
void Solve()
{
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	int j=1,s1=0,mx=0; lr s2=0;
	rep(i,1,n)
	{
		++s1,s2+=a[i];
		while(a[i]*s1-s2>m) --s1,s2-=a[j],++j;
		mx=max(mx,s1);
	}
	cout<<mx<<'\n';
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T=1;
	while(T--) Solve();
	return 0;
}