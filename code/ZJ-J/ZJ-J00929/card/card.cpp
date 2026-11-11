#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int a[N], n, m;
int ans[M];
vector <int> cnt[M];
vector <int> v;
/*inline int findcard(int x){
	int len = v.size();
	for(int i = 0; i < len; i++){
		if(v[i] == x) return i;
	}
	return len;
}
*/
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int p = 1; p <= n; p++){
		v.clear();
		for(int i = 1; i <= m; i++) cnt[i].clear();
		for(int i = p; i <= n; i++){
			if(cnt[a[i]].empty()){
				v.push_back(a[i]);
				cnt[a[i]].push_back(v.size() - 1);
				continue;
			}
			cnt[a[i]].push_back(v.size());
			int fd = cnt[a[i]][0];
			while(fd < v.size()){
				cnt[v.back()].pop_back();
				v.pop_back();
			}
			v.push_back(a[i]);
		}
		for(int i = 1; i <= m; i++){
			if(!cnt[i].empty()) ans[i]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << (i == m ? '\n' : ' ');
	}
	return 0;
}
/*
MAXpts:
T1:100%AC  100
T2:100%AC  100
T3:50%TLE  50
T4:52%TLE  48
*/
