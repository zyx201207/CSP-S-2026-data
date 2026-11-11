#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010];
ll s[500010],c[500010],sum=0;
ll man=0,d[500010];
ll fd[500010];
ll cha(ll x,ll l,ll r) {
	//查第一个大于等于x的
	ll yu=r;
	while (l<r) {
		if (l>=r) break;
		ll mid=(l+r)/2;
		//cout<<mid<<endl;
		if (s[yu]-s[mid-1]-c[mid]*(mid-1)>=m) {
			l=mid+1;
		} else if (s[yu]-s[mid-1]-c[mid]*(mid-1)<m) {
			r=mid;
		}
	}
	return l;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	ll A=0,B=1;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		if(i>=2&&abs(a[i-1]-a[i])==abs(a[i-1]-a[i-2])){
			A++;
		}
	}
	sort(a+1,a+n+1);
	//类前缀和+差分求相等所需差值
	c[0]=c[1]=0;
	s[0]=s[1]=d[1]=d[0]=0;
	sum+=a[n]-a[1];
	for (int i=2; i<=n; i++) {
		c[i]=a[i]-a[i-1];
		s[i]=s[i-1]+c[i]*(i-1);//操作与a[i]相同的代价
		d[i]=c[i]+d[i-1];
		//cout<<s[i]<<' '<<c[i]<<endl;
	}
	ll len=0,now=0;
	for (ll i=1; i<=n; i++) {
		//cout<<s[i]<<endl;
		now+=c[i]*len;
		if (now<=m) {
			len++;
			//cout<<now<<endl;
		} 
		else {
			ll ch=s[i]-m;
			ll pl=cha(ch,1,i);
			now=s[i]-s[pl-1]-c[pl]*(pl-1);
			if(pl==i)now=0;
			len=i-pl+1;
		}
		//cout<<now<<' '<<len<<endl;
		man=max(len,man);
	}
	cout<<man;
	return 0;
}