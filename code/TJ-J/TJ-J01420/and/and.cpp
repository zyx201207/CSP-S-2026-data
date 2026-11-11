#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans = 0;
int maxn = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		for(int i = 1;i<=n;i++){
			maxn = max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}
	if(m==n){
		ans = a[1];
		for(int i = 2;i<=n;i++){
			ans&=a[i];
		}
		cout << ans;
		return 0;
	}
	if(m==2){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(i==j){
					continue;
				}
				int k = a[i]&a[j];
				maxn = max(maxn,k);
			}
		}
		cout << maxn;
		return 0;
	}
	sort(a+1,a+n+1);
	ans = a[n];
	for(int i = n-1;i>=n-m+1;i--){
		ans&=a[i];
	}
//		dfs(1,0);
	cout << ans;
} 
