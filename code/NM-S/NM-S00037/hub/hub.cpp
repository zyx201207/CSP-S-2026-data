#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	
	int n,m;
	cin >> n >> m;
	vector<long long> t(n);
	for(int i = 0; i < n; i++) cin >> t[i];
	
	priority_queue<pair<long long, int>
	               vector<pair<long long, int>>
	               greater<pair<long long, int>>> pq;
	for (int i = 0; i < n; i++) pq.emplace(0,i);
	
	int ans = 0;
	for (int i = 0; i < m; i++){
		long long p; cin >> p;
		auto [free_time, id]= pq.top(); pq.pop();
		long long finish = max(free time, OLL)+ t[id];
		if (finish <= p){
			ans++;
		}
		pq.emplace(finish, id);
	} 
	cout << ans << '\n';
	return 0; 
