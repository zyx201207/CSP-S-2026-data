#include<bits/stdc++.h>
using namespace std;
int a[200010][35];
bool vis[200010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		int t;
		cin>>t;
		for(int j=0; j<=30; j++) {
			a[i][j]=t%2;
			t/=2;
		}
		vis[i]=1;
	}
	int ans=0;
	for(int j=30; j>=0; j--) {
		int cnt=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i])continue;
			if(a[i][j])cnt++;
		}
		if(cnt>=k) {
			for(int i=1; i<=n; i++) {
				if(!vis[i])continue;
				if(!a[i][j])vis[i]=0;
			}
			ans+=(1<<j);
		}
	}
	cout<<ans;
	return 0;
}