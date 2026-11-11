#include <bits/stdc++.h>
using namespace std;
long long dp[200009],n,m,a[200009],vis[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin >> n>>m;
	bool ok=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] != i-1) ok=0;
	}
	
	if(ok){
		int ans=a[n],j=n-1;
		for(int i=1;i<m;i++){
			ans = (ans&a[j--]);
		}
		cout << ans;
		return 0;
	}else{
		sort(a+1,a+n+1,greater<int>());
		dp[1]=a[1],vis[1]=1;
		for(int j=2;j<=m;j++){
			int pos=0;
			for(int i=2;i<=n;i++){
				if(vis[i] == 1) continue;
				if((dp[j-1]&a[i]) > dp[j]) {
					dp[j]=(dp[j-1]&a[i]);
					pos=i;
				}
			}
			vis[pos]=1;
		}
		cout <<dp[m];
	}
	
	return 0;
}
