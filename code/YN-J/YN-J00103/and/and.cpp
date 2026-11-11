#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
		ans=max(ans,max(a[i]&a[i+1],a[i+1]&a[i+2]));
	cout<<ans;
	return 0;
}
