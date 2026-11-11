#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+10;

int n,m,p;
int a[N];
int t[32+5][N];
vector<int> ve;
vector<int> g;
void f(int x,int id){
	int cnt = 0;
	while (x){
		t[cnt][id] = x % 2;
		x /= 2;
		cnt++;
	}
}

void print(){
	int ans = a[ve[0]];
	for (auto it : ve){
		ans &= a[it];
	}
	cout << ans;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i];
		f(a[i],i);
	}
	for (int i = 31 ; i >= 0 ; i--){
		int s = 0;
		for (int j = 1 ; j <= n ; j++){
			s += t[i][j];
		}
		if (s >= m){
			p = i;
			for (int j = 1 ; j <= n ; j++){
				if (t[i][j] == 0)continue;
				ve.push_back(j);
			}
			break;
		}
	}
	if (ve.size() == 0){
		cout << 0;
		return 0;
	}
	if (ve.size() == m){
		print();
		return 0;
	}
	for (int i = p-1 ; i >= 0 ; i--){
		if (g.size() == 0){
			int s = 0;
			for (auto it : ve){
				s += t[i][it];
			}
			if (s == m){
				vector<int> k = ve;
				ve.clear();
				for (auto it : k){
					if (t[i][it] == 0)continue;
					ve.push_back(it);
				}
				print();
				return 0;
			}
			if (s > m){
				vector<int> k = ve;
				ve.clear();
				for (auto it : k){
					if (t[i][it] == 0)continue;
					ve.push_back(it);
				}
			}
			else{
				vector<int> k = ve;
				ve.clear();
				for (auto it : k){
					if (t[i][it] == 0)g.push_back(it);
					else ve.push_back(it);
				}
			}
		}
		else{
			int s = 0;
			for (auto it : ve){
				s += t[i][it];
			}
			for (auto it : g){
				s += t[i][it];
			}
			if (s == m){
				vector<int> k = ve;
				ve.clear();
				for (auto it : k){
					if (t[i][it] == 0)continue;
					ve.push_back(it);
				}
				for (auto it : g){
					if (t[i][it] == 0)continue;
					ve.push_back(it);
				}
				print();
				return 0;
			}
			if (s > m){
				vector<int> k = ve;
				ve.clear();
				for (auto it : k){
					if (t[i][it] == 0)continue;
					ve.push_back(it);
				}
				for (auto it : g){
					if (t[i][it] == 0)continue;
					ve.push_back(it);
				}
			}
			else{
				vector<int> k = ve;
				vector<int> kk = g;
				ve.clear();
				g.clear();
				for (auto it : k){
					if (t[i][it] == 0)g.push_back(it);
					else ve.push_back(it);
				}
				for (auto it : kk){
					if (t[i][it] == 0)g.push_back(it);
					else ve.push_back(it);
				}
			}
		}
	}
	int ans = 0;
	for (auto it : ve)ans = a[it];
	for (auto it : g)ans = a[it];
	for (auto it : ve)ans &= a[it];
	for (auto it : g)ans &= a[it];
	cout << ans;
	
	return 0;
}
