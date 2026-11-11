#include<bits/stdc++.h>
#define int long long
#define vi void
#define pii pair<int,int>
using namespace std;

int n,m,mx=-1,sd,tmp,cnt;
bool ffgg=1;

vi ssvv() {
	int x=0;
	for(int i=1; i<=n; i+=sd) {
		x+=i;
		if(x>=m) {
			cout<<i;
			return;
		}
//		cout<<x<<' ';
	}
	cout<<n;
	return;
}

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	long a[n+5];
//	puts("!");

	for(int i=1; i<=n; i++) {
		cin>>a[i];
//		if(a[i]!=i) fg=0;
		if(i==2) sd=a[i]-a[i-1];
		if(i>2) {
			if(a[i]-a[i-1]!=sd) {
				ffgg=0;
			}
		}
	}
//	if(fg) {
//		solve();
//		exit(0);
//	}
	if(ffgg) {
		ssvv();
		exit(0);
	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	for(int i=n; i>=1; i--) {
//		puts("!");
//		cout<<i<<':';
		if(mx!=-1&&i<=mx) {
			break;
		}
		tmp=m;
		cnt=1;
		for(int j=i-1; j>=1; j--) {
			if(tmp>=a[i]-a[j]) {
//				cout<<j<<' '<<tmp<<' '<<a[i]-a[j]<<' ';
				cnt++;
				tmp-=a[i]-a[j];
//				cout<<tmp<<'\n';
			} else {
				break;
			}
		}
		mx=max(mx,cnt);
//		cout<<cnt<<endl;
//		puts("!");
	}
	cout<<mx;
	return 0;
}

