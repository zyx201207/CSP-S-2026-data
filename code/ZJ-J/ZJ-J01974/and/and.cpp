#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],s;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	s=a[n];
	for(int i=2;i<=m;i++){
		s=s&a[n-i+1];
	}
	cout<<s;
	return 0;
}
