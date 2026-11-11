#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(a,b,c) for(int a=b;a<=c;++a)
#define dep(a,b,c) for(int a=b;a>=c;--a)
const int N = 1e6+7; const int inf = 1e9+7;
int n,m,a[N],c[N],ans=1,l=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n) c[i]=a[i]+c[i-1];
	//rep(i,0,n) cout<<c[i]<<" ";//ts
	//cout<<endl;//ts
	//cout<<a[3]*(3-1+1)-(c[3]-c[0])<<" "<<a[3]<<" "<<c[3]-c[0]<<endl;//ts
	rep(r,1,n)
	{
		while( a[r]*(r-l+1)-(c[r]-c[l-1])>m ) l++;
		ans=max(ans, (r-l+1) );
		//cout<<l<<" "<<r<<"   :   "<<ans<<endl;//ts
	}
	cout<<ans;
	return 0;
}
