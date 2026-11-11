#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, m, num[maxn], ans[maxn];
vector <int> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			for(int k = 0; k < v.size(); k++){
				if(v[k] == num[j]) {
					for(int m = v.size() - 1; m >= k; m--) v.pop_back();
					break;
				}
			}
			v.push_back(num[j]);
		}
		while(!v.empty()){
			ans[v.back()]++;
			v.pop_back();
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
