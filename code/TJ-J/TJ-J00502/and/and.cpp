#include<bits/stdc++.h>
using namespace std;
int a[200010];
//int f[200010][200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(m = n - 1){
		long long maxn = -1e18;
		for(int i = 1;i <= n;i++){
			long long ans = 0;
			for(int j = 1;j <= n;j++){
				if(j == i) continue;
				ans = ans & a[j];
			} 
			maxn = max(maxn,ans);
		} 
		cout << maxn;
	}else if(m == 1){
		sort(a + 1,a + n + 1);
		cout << a[n];
	}else if(m == n){
		long long ans = 1;
		for(int i = 1;i <= n;i++){
			ans = ans & a[i];
		} 
		cout << ans;
	}else{
		int f[200010][200010];	
		f[0][0] = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j < m;j++){
				f[i][j] = max(f[i-1][j],f[f[i-1][j] & a[i]][j+1]);
			}
		} 
		int maxn = INT_MIN;
		for(int i = 1;i <= n;i++){
			for(int j = 1;i <= m;j++){
				maxn = max(f[i][j],maxn);
			} 
		}
		cout << maxn;
	}
	return 0;
}
