//error in 3&4
#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll> b(n);
	for(int i=0;i<n;++i) cin>>b[i];
	if(n==1||m==2) return cout<<1,0;
	if(n==2) {
		if(b[1]-b[0]<=m) {
			cout<<2;
		}else {
			cout<<1; 
		}
		return 0;
	}
	sort(b.begin(),b.end());
	ll b0=b[0];
	for(ll i=0;i<n;++i) {
		b[i]-=b0;
//		cout<<b[i]<<" ";//
	}
//	cout<<endl;//
	vector<ll> a(n);
	a[0]=b[0];
	for(ll i=1;i<n;++i) {
		a[i]=a[i-1]+b[i];
//		cout<<a[i]<<" ";//
	}
//	cout<<endl<<endl;//
	ll maxn=0,l=1,s=1,c=0;
	bool f=1;
	for(ll r=1;r<n;++r) {
//		cout<<endl<<endl;//
		if(c>m) {
//			cout<<"l="<<l<<" r="<<r<<" c="<<c<<" m="<<m;//
			c-=b[r-1]-b[l];
			l++;
			f=0;
			maxn=max(maxn,s);
			s--;
//			r--;
			continue;
		}
		f=1;
		s++;
//		cout<<c<<" "<<s*b[r]-a[r-1];//
		c+=s*b[r]-a[r-1];
	}
//	cout<<endl;//
	if(f) {
		s++; 
	}
	cout<<max(maxn,s);
	return 0;
}
