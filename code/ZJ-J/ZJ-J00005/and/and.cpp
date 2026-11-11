#include<bits/stdc++.h>

using namespace std;

long long a[200010];
int vis[200010];
int vis2[200010];

vector<int> G[200010];

int n, m;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
//	cout << (1 << 30) << "\n";
	for(int i = 1; i <= n; i++){
		vis[i] = 1;
		cin >> a[i];
		for(int j = 0; j <= 30; j++){
			if(a[i] & (1 << j)){
				G[j].push_back(i);
			}
		}
	}
	long long ret = 0;
	for(int i = 30; i >= 0; i--){
//		cout << G[i].size() << "\n";
		for(int j = 1; j <= n; j++){
			vis2[j] = 0;
		}
		int ge = 0;
		if(G[i].size() >= m){
			for(int j : G[i]){
				if(vis[j] == 1){
					vis2[j] = 1;
					ge++;
				}
			}
		}
		if(ge >= m){
			ret += (1 << i);
			for(int j = 1; j <= n; j++){
				vis[j] = vis2[j];
			}
		}
	}
	cout << ret;
	
	return 0;
}