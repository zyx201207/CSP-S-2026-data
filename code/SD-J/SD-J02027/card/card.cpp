#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int cnt[300005];
queue<int> st;
bool find(int b){
	if (st.empty()) return false;
	vector<int> v;
	while (!st.empty()){
		v.push_back(st.front());
		st.pop();
	}
	for (int i = 0; i < v.size(); i++){
		st.push(v[i]);
	}
	for (int i = 0; i < v.size(); i++){
		if (v[i] == b) return true;
	}
	return false;
}
int main(){
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		while (!st.empty()){
			st.pop();
		}
		for (int j = i; j <= n; j++){
			if (find(a[j])){
				while (!st.empty()){
					st.pop();
				}
			}
			st.push(a[j]);
		}
		while (!st.empty()){
			cnt[st.front()]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
