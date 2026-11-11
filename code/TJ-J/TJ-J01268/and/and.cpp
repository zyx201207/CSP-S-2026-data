#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[200001],mx,ans = (1ll << 31) - 1,cnt,ans2;
int n,m,vis[21],flag = 1;
void dfs(int dep){
	if (dep > m){
		long long x = (1ll << 31) - 1;
		for (int i = 1;i <= n;i++)
			if (vis[i])
				x = x & a[i];
		ans2 = max(ans2,x);
	}
	for (int i = 1;i <= n;i++)
		if (!vis[i]){
			vis[i] = 1;
			dfs(dep+1);
			vis[i] = 0;
		}
}
bool cmp(long long a,long long b){return a > b;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		mx = max(mx,a[i]);
		ans = ans & a[i];
		if (a[i] != i-1) flag = 0;
	}
	if (m == 1) cout << mx;
	else if (m == n) cout << ans;
	else if (m == 2){
		for (int i = 1;i <= n;i++)
			for (int j = 1;j < i;j++)
				cnt = max(cnt,a[i] & a[j]);
		cout << cnt;
	}
	else if (n <= 20){
		dfs(1);
		cout << ans2;
	}
	else if (mx < 4){
		int cnt1 = 0,cnt2 = 0,cnt3 = 0;
		for (int i = 1;i <= n;i++){
			if (a[i] == 3) cnt3++;
			if (a[i] == 2) cnt2++;
			if (a[i] == 1) cnt1++;
		}
		if (cnt3 >= m) cout << 3;
		else if (cnt3 + cnt2 >= m) cout << 2;
		else if (cnt3 + cnt1 >= m) cout << 1;
		else cout << 0; 
	}
	else if (n == ~n+1 && flag){
		long long sum = 1,k = 0,sum2 = 1,k2 = 0,dui = 1;
		while (sum < m){
			sum *= 2;
			k++;
		}
		while (sum2 < n){
			sum2 *= 2;
			k2++;
		}
		for (int i = 1;i <= k2-k;i++) dui *= 2;
		cout << n - dui;
	}
	else{
		sort(a+1,a+n+1,cmp);
		cout << a[m];
	}
	return 0;
}
