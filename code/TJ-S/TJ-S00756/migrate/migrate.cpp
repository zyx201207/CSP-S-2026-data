#include <iostream>
#include <cstdio>
using namespace std;
long long a[501],vis[501],ans,cnt,n,d;
void dfs(int dep,int l,int r){
	if (dep >= cnt){
		int lst = l,flag = 0;
		for (int i = l+1;i < r;i++){
			if (vis[i] == 1){
				if (a[i] - a[lst] <= d) lst = i;
				else{
					flag = 1;
					break;
				}
			}
		}
		if (a[r] - a[lst] <= d && flag == 0) ans++;
		return;
	}
	for (int i = l+1;i < r;i++)
		if (!vis[i]){
			vis[i] = 1;
			dfs(dep+1,l,r);
			vis[i] = 0;
		}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1;i <= n;i++) cin >> a[i];
		a[n+1] = 4e18;
		int num = 0;
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				for (int k = 1;k <= n;k++) vis[k] = 0;
				int k = i;
				ans = 0,cnt = 1;
				while (k < j) {
					int x = k;
					while (a[k] - a[x] <= d && k <= j) k++;
					if (k > j) break;
					cnt++;
				}
				dfs(1,i,j);
				if (ans == 2) num++;
			}
		}
		cout << num << endl;
	}
	return 0;
}
