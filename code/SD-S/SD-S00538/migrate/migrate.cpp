#include <bits/stdc++.h>
using namespace std;

#define int long long

int c,t;
int n,d;
int a[2000001];

int r,mn,ans;
int f[1001][1001];
int p;

void dfs(int i,int sum){
	if(f[p][i] < sum) return;
	f[p][i] = sum;
	if(i == r){
		if(sum < mn){
			mn = sum;
			ans = 1;
		}else if(sum == mn)
			ans++;
		return;
	}
	int x = 0;
	for(int j = r;j >= i + 1;j--){
		if(a[j] - a[i] <= d)	
			dfs(j,sum+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		int ans2 = 0;
		for(int i = 1;i <= n;i++)
			cin >> a[i];
		for(int i = 1;i < n;i++){
			p = i;
			for(int j = i + 1;j <= n;j++){
				for(int k = i;k <= j;k++)
					f[p][k] = 1e18;
				mn = 2e9;
				r = j;
				ans = 0;
				dfs(i,0);
				if(ans == 2)
					ans2++;
			}
		}
		cout << ans2 << '\n';
	}
	return 0;
}

