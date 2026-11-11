#include <bits/stdc++.h>
using namespace std;
int a[200005];
//int cntz[100];//在所有数中每位共有多少个一 
//vector <int> have[50];//记录有相同位的数的下标 
//vector <int> numw[200005]; //有哪些位为一 
//vector <int> temv;
//void fg(int x, int ind){
//	int cnt = 0;
//	while(x){
//		if (x & 1){
//			cntz[cnt]++; 
//			//cout << 1;
//			have[cnt].push_back(ind);
//			numw[ind].push_back(cnt);
//		}
//		x>>=1;
//		cnt++;
//	}
//	return ;
//}
//int pown(int x){
//	int ans = 1;
//	for (int i = 1; i <= x; i++){
//		ans *= 2;
//	}
//	return ans;
//}
//int main(){
//	//freopen("and3.in", "r", stdin);
//	//freopen("and.out", "w", stdout);
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++){
//		scanf("%d", &a[i]);
//		fg(a[i], i);
//	}
//	int wei = 0;
//	for (int i = 32; i >= 0; i--){
//		if (cntz[i] >= m){
//			wei = i;
//			cout << cntz[wei];
//			break;
//		}
//	}
//	int ans = 0;
//	if (wei == 0){
//		cout << 1;
//	}
//
//	int temwei = wei-1;
//	int num = 0;
//	while(num != m && temwei >= 0){
//		num = 0;
//		temv.clear();
//		for (int i = 0; i < cntz[wei]; i++){
//			if (numw[have[wei][i]][temwei] == 1){
//				temv.push_back(have[wei][i]);
//				num++;
//			}
//		}
//	}
//	if (num != m && temwei == 0){
//		cout << pown(wei);
//	}else{
//		ans = a[temv[0]];
//		for (int i = 1; i < int(temv.size()); i++){
//			ans = ans & a[temv[i]];
//		}
//		cout << ans;
//	}
//	return 0;
//}
int n, m, maxi = 0;
bool vis[200005];
void dfs(int x, int ans){
	if (x == m){
		maxi = max(maxi, ans);
		return ;
	}
	for(int i = 1; i <= n; i++){
		if (vis[i]){
			continue;
		}
		vis[i] = 1;
		if (x == 0){
			dfs(x+1, a[i]);
		}else{
			dfs(x+1, ans & a[i]);
		}

		vis[i] = 0;
	} 
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (m == 1){
		int mx = 0;
		for (int i = 1; i <= n; i++){
			mx = max(a[i], mx);
		}
		cout << mx;
		return 0;
	}
	if (m == 2){
		int mx = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i == j){
					continue; 
				}
				mx = max(a[i] & a[j], mx);
			}
		}
		cout << mx;
		return 0;
	}
	if (m == n){
		int ans = a[1];
		for (int i = 2; i <= n; i++){
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	dfs(0, 0);
	cout << maxi;
	return 0;
}
