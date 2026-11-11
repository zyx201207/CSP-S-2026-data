#include<bits/stdc++.h>
using namespace std;

int n, m, ans;
int a[200005];
vector<int> p[35];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	for(int i = 1; i <= n; i++){
		int x = a[i], cnt = 0;
		while(x){
			if(x & 1 == 1) p[cnt].push_back(a[i]);
			x >>= 1;
			cnt++;
		}
	}
	
	int i = 31;
	vector<int> x;
	for(; i >= 0; i--){
		if(p[i].size() >= m){
			x = p[i];
			break;
		}
	}
	
	for(i--; i >= 0 && x.size() > m; i--){
		vector<int> d;
		for(int it : x){
			int l = 0, r = p[i].size() - 1;
			while(l <= r){
				int mid = (l + r) / 2;
				if(p[i][mid] == it){
					d.push_back(it);
					break;
				}
				else if(p[i][mid] > it) r = mid - 1;
				else l = mid + 1;
			}
		}
		if(d.size() >= m) x = d;
	}
	
	ans = x[0];
	for(int it : x) ans &= it;
	cout << ans;
	
	return 0;
}
