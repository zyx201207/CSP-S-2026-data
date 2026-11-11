#include<iostream>
#include<stdio.h>
#include<bits/stl_algo.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	long long a[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=-1;
	if(((m)/(long long)(n))>=a[n-1]-a[0]) {
		cout<<n<<'\n';
		return 0;
	}
//	cout<<a[n-1]-a[0]<<'\n';
	long long ene=0;
	int res=0;
	for(int i=n-1; i>=ans; i--) {
		int pos=i-res;
		ene-=((a[i+1]-a[i])*res);
		while(pos>=0&&ene<=m) {
			ene+=(a[i]-a[pos]);
			pos--;
		}
		ans=max(ans,i-pos);
		res=i-pos-1;
	}
	cout<<ans<<'\n';
	return 0;
}
