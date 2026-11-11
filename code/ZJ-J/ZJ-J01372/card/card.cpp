#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int n, m;
int vis[N];
int ans[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)cin >> a[i];
	for(int i = 1 ; i <= n ; i++){
		for(int j = i ; j <= n ; j++){
			if(vis[a[j]] == 0)vis[a[j]] = j;
			else{
				for(int k = vis[a[j]] ; k < j ; k++)vis[a[k]] = 0;
				vis[a[j]] = j;
			}
		}
		for(int j = 1 ; j <= m ; j++){
			if(vis[j] > 0)ans[j]++;
			vis[j] = 0;
		}
	}
	
	for(int i = 1 ; i <= m ; i++)cout << ans[i] << ' ';
	return 0;
}
