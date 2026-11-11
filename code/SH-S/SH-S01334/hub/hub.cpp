#include<bits/stdc++.h>
using namespace std;
void solve(){
	vector<int> ve[500010];
	int in[500010] = {};
	int n , k;
	cin >> n >> k;
	for(int i = 1 ; i <n ; i++){
		int u , v;
		cin >> u >> v;
		ve[u].push_back(v);
		in[u]++;
		ve[v].push_back(u);
		in[v]++;
	}
	sort(in + 1 , in + n);
	int flag = n;
	for(int i = n ; i >= 1 ; i++){
		flag -= in[i];
		if(flag <= 0){
			cout << i << '\n';
			break;
		}
	}
}
int main(){
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	int c , t;
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
