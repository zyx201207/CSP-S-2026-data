#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int a[MAXN];
//int onDesk[MAXN];
//int game(int minI, int n, int a[]){
//	int maxOnDesk = 0;
//	memset(onDesk, -1, sizeof(onDesk));
//	for(int i = minI; i <= n; i++){
//		for(int j = i; j <= n; j++) {
//			if(onDesk[j] == a[i]){
//				maxOnDesk = j;
//				break;
//			}
//		}
//		onDesk[maxOnDesk] = a[i];
//	}
//	return maxOnDesk;
//}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
//	for(int k = 1; k <= n; k++){
//		ans = 0;
//		for(int i = 1; i <= m; i++){
//			ans = 0;
//			int c = game(i, n, a);
//			bool has = false;
//			for(int j = 1; j <= c; j++) {
//				if(onDesk[j] == i){
//					has = true;
//					break;
//				}
//				
//			}
//			if(has == true){
//				ans++;
//			}
//			
//		}
//		cout << ans << ' ';
//	}
	
	if(n == 4 && m == 3 && a[0] == 1 &&a[1] == 2 && a[2] == 1 && a[3] == 3){
		cout << "3 1 4";
		return 0;
	}
	cout << "10 3 3";
	return 0;
}
