#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<long long> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<bool> vis(n+1,1);
	for(int i=30;i>=0;i--) {
		int cnt=0;
		for(int j=1;j<=n;j++) {
			if(a[j]>>i&1&&vis[j]) cnt++;
		}
		if(cnt<m) continue;
		for(int j=1;j<=n;j++) {
			if(!(a[j]>>i&1)) vis[j]=0;
		}
		if(cnt==m) break;
	}
	int cnt2=0;
	long long ans=0;
	for(int i=1;i<=n;i++) {
		if(vis[i]) {
			if(cnt2==0) ans=a[i];
			else ans&=a[i];
			cnt2++;
			if(cnt2==m) break;
		}
	}
	cout<<ans<<"\n";
 	return 0;
}