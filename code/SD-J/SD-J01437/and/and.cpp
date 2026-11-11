#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
const int M = 35;
int is[N][M];
int n, m;
vector<int> vec[M + 1];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		int k;
		cin >> k;
		vec[M].push_back(i);
		int tot = 0;
		while(k > 0){
			if(k % 2 == 1)is[i][tot] = 1;
			tot++;
			k /= 2;
		}
	}
	long long ans = 0;
	for(int j = M - 1; j >= 0; j --){
		int tot = 0;
		for(auto u : vec[j + 1])if(is[u][j] == 1)tot++;
		if(tot >= m){
			for(auto u : vec[j + 1])if(is[u][j] == 1)vec[j].push_back(u);
			ans += (1ll << j);
		}
		else{
			for(auto u : vec[j + 1])vec[j].push_back(u);
		}
	}
	cout << ans << "\n";
	return 0;
}
