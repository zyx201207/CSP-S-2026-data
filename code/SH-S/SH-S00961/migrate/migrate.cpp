#include <bits/stdc++.h>

using namespace std;

const int N = 2e6+5;
int c,t;
long long n,d;
long long a[N];

int dfs(int l,int r,int k,int target) {
	if(k == target && l == r) {
		return 1;
	}
	if(k == target && l != r) {
		return 0;
	}
	int ans = 0;
	for(int i = l+1;i <= r;i++) {
		if(a[i] - a[l] <= d) {
			ans += dfs(i,r,k+1,target);
		}else{
			return ans;
		}
	}
}

bool check(int l,int r) {
	long long better_past = 0,now = l;
	for(int i = l+1;i <= r;i++) {
		if(a[i] - a[now] > d) {
			if(i == now+1) return false;
			now = i-1;
			better_past++;
			i--;
		}
	}
	better_past++;
	if(better_past == 1) return false;
	if(dfs(l,r,0,better_past) == 2) return true;
	return false;
}

int main() {
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		int ans = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = i+1;j <= n;j++) {
				if(check(i,j)) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

