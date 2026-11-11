#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N];
char c[N];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,ans=0;
	while(l<r){
		int x=min(a[l],a[r]);
		if (c[l]!=c[r]) ans+=x;
		a[l]-=x,a[r]-=x;
		if (a[l]<=0) l++,a[l]+=a[l-1]; 
		if (a[r]<=0) r--,a[r]+=a[r+1];
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
