#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],x=0,ans=1,j=0;
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;++i) cout<<a[i]<<' ';
	if(n%2==0) x=a[n/2];
	else x=a[n/2+1];
	//cout<<x;
	for(int i=1;i<=n;++i) if(a[i]==x) ans++;
	for(int i=1;;) {
		for(;;) {
			if(a[i]==x) {
				ans++;
				i++;
				break;
			}
			if(a[i]<x&&m>0) {
				a[i]++;
				m--;
			}
			if(m==0) {
				cout<<ans;
				return 0;
			}
		}

	}
	return 0;
}
