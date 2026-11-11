#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int n,m;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int ans=a[1];
	for (int i=1;i<=m;i++) {
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}

