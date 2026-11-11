#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[1000010];
int main() {
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; ++i) {
			cin>>a[i];
		}
		cout<<a[1]<<endl;
	}
	return 0;
}
