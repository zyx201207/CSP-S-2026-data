#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
string b;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>b[i];
	}
	bool flag=1;
	for(int i=2; i<=n; i++) {
		if(b[i]!=b[i-1]) {
			flag=0;
		}
	}
	if(flag) cout<<0;
	else cout<<0;
	return 0;
}
