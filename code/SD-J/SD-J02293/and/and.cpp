#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e7+10;
int n,m;
int a[N];
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<max(n,m);
	return 0;
}
