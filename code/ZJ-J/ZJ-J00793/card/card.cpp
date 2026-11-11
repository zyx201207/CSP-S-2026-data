#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N = 500001;
int n, m, a[N], ans[300001];
bool can[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		memset(can, 0, sizeof can);
		for(int j = i; j <= n; j++){
			bool flag = 0;
			for(int k = i; k <= j - 1; k++){
				if(can[k]) continue;
				if(a[k] == a[j]){
					flag = 1;
				}
				if(flag){
					can[k] = 1;
				}
			}
		}
		for(int j = i; j <= n; j++){
			if(!can[j]) ans[a[j]]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
