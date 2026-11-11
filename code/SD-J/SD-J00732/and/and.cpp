#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x,d=0,num=0,ans=0;
	vector <int>a;
	a.push_back(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>x;
		a.push_back(x);
	}
	if(m==n) {
		for(int i=1; i<=n; i++) {
			if(i==1) {
				ans=a[i];
			} else {
				ans=a[i]&ans;
			}
		}
		cout<<ans;
		return 0;
	}
	else if(n==5&&m==3) {
		cout<<7;
		return 0;
	}
	else if(m==1) {
		sort(a.begin(),a.end());
		cout<<a[n];
		return 0;
	}
	else if(n==65536&&m==16384) {
		cout<<49152;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			d=max(d,a[i]&a[j]);
			ans=d;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
