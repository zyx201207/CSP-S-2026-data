// jrlzy 1 crystal
#include <bits/stdc++.h>
#define LL long long
#define SH short
#define DB long double
const int N=500005;
using namespace std;
int n,t; LL a[N],s[N],m;
void mian ()
{
	cin>>n>>m; for (int i=1;i<=n;++i) cin>>a[i]; sort(a+1,a+n+1);
	for (int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	for (int r=1,l=0;r<=n;++r)
	{
		while (l<r&&1LL*(r-l+1)*a[r]-s[r]+s[l-1]>m) ++l; t=max(t,r-l+1);
	}
	cout<<t;
}
int main ()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	int T; cin>>T; while (T--)
		mian();
	exit(0);
}
