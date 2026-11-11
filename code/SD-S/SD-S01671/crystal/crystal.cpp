#include<bits/stdc++.h>//rp++
#define int long long
using namespace std;
int n,m,a[500003],d,pre[500003];
bool sitA=1,sitB=1;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(i==2)d=a[i]-a[1];
		if(a[i]!=i)sitA=0;
		if(a[i]-a[i-1]!=d&&i!=1)sitB=0;
	}
	if(sitA) {
		for(int i=1; i<=n; i++) {
			if((n*n-n)/2>m) {
				cout<<i-1;
				return 0;//rp++
			}
		}
		cout<<n;
		return 0;
	}
	if(sitB) {
		for(int i=1; i<=n; i++) {
			if((d+a[i]-a[1])*(i-1)/2>m) {
				cout<<i-1;
				return 0;
			}//rp++
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++)
		pre[i]=pre[i-1]+a[i];
	for(int i=1; i<=n; i++) {
		if(a[i]*i-pre[i]>m) {
			cout<<i-1;
			return 0;//rp++
		}
	}
	cout<<n;
	return 0;
}//rp++
