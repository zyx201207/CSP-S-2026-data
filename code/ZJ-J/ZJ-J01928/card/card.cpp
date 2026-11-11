#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],f[300005],ans[300005];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	int jh=0;
	for(int i=1; i<=n; i++)
		if(a[i]<a[i-1]) {
			jh=1;
			break;
		}
	if(jh==0) {
		for(int i=2; i<=n; i++)
			if(a[i]!=a[i-1])
				cout<<i-1<<" ";
		return 0;
	}
	for(int k=1; k<=n; k++) {
		int cnt=0;
		for(int i=k; i<=n; i++) {
			int jh=0;
			for(int j=1; j<=cnt; j++)
				if(f[j]==a[i]) {
					cnt=j,jh=1;
					break;
				}
			if(jh==0)f[++cnt]=a[i];
		}
		for(int i=1; i<=cnt; i++)
			ans[f[i]]++;
	}
	for(int i=1; i<=m; i++)
		cout<<ans[i]<<" ";
	return 0;
}