#include<bits/stdc++.h>
//#define debug
typedef long long ll;
using namespace std;
const int N=5e5+100;//M=1e18! ll!
ll a[N],s[N];
int n,m;
inline ll f(int i,int j) {
	return j*a[i]-s[i]+s[i-j];
}
bool check(int x) {
	ll res=LLONG_MAX;
	for(int i=x; i<=n; i++)
		res=min(res,f(i,x));
	return m>=res;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)
		s[i]=s[i-1]+a[i];
	int l=1,r=n,mid,ans;
	bool res;
	while(l<=r) {
		mid=(l+r)>>1;
		res=check(mid);
		if(res) { //cost too low-> l up
			l=mid+1;
			ans=mid;
		} else
			r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}

