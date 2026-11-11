#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans[500005];
bool vis[500005],p[500005];
bool check() {
	for(int i=2;i<n;i++) {
		if(a[i-1]>a[i]) {
			return false;
		}
	}
	return  true;
}
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	bool l=check();
	for(int i=1;i<=n;i++) {
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++) {
			int res=0;
			if(l) {
				if(a[j-1]==a[j]&&!vis[j-1]) {
					res=j-1;
				}
			} else {
				for(int k=j-1;k>=i;k--) {
					if(a[k]==a[j]&&!vis[k]) {
						res=k;
						break;
					}
				}
			}
//			cout<<i<<" "<<j<<" "<<res<<"\n";
			if(res>0) {
				for(int k=res;k<j;k++) {
					vis[k]=true;
				}
			}
		}
		memset(p,0,sizeof p);
		for(int j=i;j<=n;j++) {
			if(!vis[j]) {
				p[a[j]]=true;
			}
		}
		for(int j=1;j<=m;j++) {
			if(p[j]==true) {
			++ans[j];			
			}
		}
	}
	for(int i=1;i<=m;i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}