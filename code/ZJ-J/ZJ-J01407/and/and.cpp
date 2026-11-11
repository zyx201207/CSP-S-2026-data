#include <bits/stdc++.h>
using namespace std;
int n,k,maxx_p,a[200005];
bool vis[200005];
void dfs(int u,int sum){
	if(u == k+1){
		maxx_p = max(maxx_p,sum);
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(u+1,sum & a[i]);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int maxx = -1000;
	bool flag = 0;
	cin >> n >> k;
	cin >> a[1];
	int sum = a[1];
	for(int i = 2;i <= n;i++){
		cin >> a[i];
		maxx = max(a[i],maxx);
		if(a[i] >= 4)flag = 1;
		sum&=a[i];
	}
	if(n == k){
		cout << sum;
		return 0;
	}
	else if(k == 1){
		cout << maxx;
		return 0;
	}
	else if(k == 2){
		int gwmaxx = -1000;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j)continue;
				gwmaxx = max(gwmaxx,(a[i]&a[j]));
			}
		}
		cout << gwmaxx;
		return 0;
	}
	else if(flag == 0){
		sort(a+1,a+1+n);
		int dsf = a[n];
		for(int i = n-1;i >= (n-k+1);i--){
			dsf&=a[i];
		}
		cout << dsf;
		return 0;
	}
	dfs(1,1048575);
	cout << maxx_p;
	return 0;
}