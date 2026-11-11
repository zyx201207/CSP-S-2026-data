#include<bits/stdc++.h>
#define QwQ 0
#define debug cout << "!!!" << "\n";
using namespace std;
int n, m, tot, ans;
int a[200010], b[40];
int f[200010], flag, c[40];
vector<int> t[40];
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	c[0] = 1;
	for(int i = 1; i <= 30; i++){
		c[i] = c[i - 1] * 2;
	}
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		memset(b, 0, sizeof b);
		int tot1 = 0;
		while(x){
			b[tot1++] = (x & 1);
			x >>= 1;
		}
		int u = 0;
		for(int j = 30; j >= 0; j--){
			if(b[j]){
				t[j].push_back(i);
			}
		}
	}
	for(int i = 30; i >= 0; i--){
		if(t[i].size() < m)	continue;
		if(flag == 0){
			flag = 1;
			for(auto v : t[i])	f[v] = 1;
			ans += c[i];
		}else{
			int cnt = 0;
			for(auto v : t[i]){
				if(f[v] == flag){
					cnt++;
				}
			}
			if(cnt < m)	continue;
			for(auto v : t[i]){
				if(f[v] == flag){
					f[v]++;
				}
			}
			flag++;
			ans += c[i];
		}
	}
	cout << ans << '\n';
	return QwQ;
}