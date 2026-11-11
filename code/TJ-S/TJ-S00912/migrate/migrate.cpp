#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,m;
int a[2000005];
int dp[3005][3005];
int tot = 0;
void floyd(){
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
void solve(){
	tot = 0;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i==j){
				dp[i][j] = 0;
			}
			dp[i][j] = 1e9;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			dp[i][j] = abs(a[i]-a[j]);
			dp[j][i] = abs(a[i]-a[j]);
		}
	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			cout << dp[i][j] << ' ';
//		}
//		cout << endl;
//	}
	floyd();
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			cout << dp[i][j] << ' ';
//		}
//		cout << endl;
//	}
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(i==j){
				continue;
			}
			int u = i;
			int v = j;
			int ans = 0;
			for(int k = 1;k<=n;k++){
				if(k==u||k==v){
					continue;
				}
//				cout << u << "->" << k << ':'<<dp[u][k] << ' ' << k << "->" << v << ':' << dp[k][v] << ' ' << u << "->" << v  << ':' << dp[u][v] <<endl;
				if(dp[u][k]+dp[k][v]==dp[u][v]){
					
					ans++;
				}
			}
//			cout<< endl;
			if(ans==2){
				tot++;
			} 
		}
	} 
	cout << tot << endl;
} 

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		solve();
	} 	
}
//#include<bits/stdc++.h>
//using namespace std;
//int c,T;
//int n,m;
//int a[100005];
//int dp[3005][3005];
//int tot = 0;
//void floyd(){
//	for(int k = 1;k<=n;k++){
//		for(int i = 1;i<=n;i++){
//			for(int j = 1;j<=n;j++){
//				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
//			}
//		}
//	}
//}
//void solve(){
//	tot = 0;
//	cin >> n >> m;
//	for(int i = 1;i<=n;i++){
//		cin >> a[i];
//	}
//	cout<< 0 << endl;
//} 
//
//int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
//	cin >> c >> T;
//	while(T--){
//		solve();
//	} 	
//}
//#include<bits/stdc++.h>
//using namespace std;
//int c,T;
//int n,m;
//int a[100005];
//int dp[3005][3005];
//int tot = 0;
//void floyd(){
//	for(int k = 1;k<=n;k++){
//		for(int i = 1;i<=n;i++){
//			for(int j = 1;j<=n;j++){
//				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
//			}
//		}
//	}
//}
//void solve(){
//	tot = 0;
//	cin >> n >> m;
//	for(int i = 1;i<=n;i++){
//		cin >> a[i];
//	}
//	cout<< 0 << endl;
//} 
//
//int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
//	cin >> c >> T;
//	while(T--){
//		solve();
//	}
//	
//	
//}
