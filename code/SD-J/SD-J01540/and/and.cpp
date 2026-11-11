#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200010;
int ans;
int n, m;
int a[N];
vector<int> v[35];
void solve2(vector<int> vec, int p){
	int q = 0;
//	vector<int> ve;
	for(int i = p - 1; i >= 0; i --){
//		if(ve.empty()){
//			for(int j = 0; j < vec.size(); j ++){
//				if(vec[j] & (1 << p)){
//					ve.push_back(a[j]);
//				}
//			}
//			if(ve.size() < m){
//				ve.clear();
//			}else{
//				ans |= (1 << p);
//			}
//		}else{
			vector<int> nve;
			for(int j = 0; j < vec.size(); j ++){
				if((vec[j] & (1 << i)) == (1 << i)){//这一行调了半小时 
					nve.push_back(vec[j]);
				}
			}
			if(nve.size() >= m){
//				cout << i << '\n'; 
				ans |= (1 << i);
				vec.clear();
				for(int e : nve){
					vec.push_back(e);
				}
			}
//		}
	}
}
void solve1(int p){
	if(p < 0){
		cout << 0;
		exit(0);
	}
	if(v[p].size() >= m){
		ans = (1 << p);
		solve2(v[p], p);
	}else{
		solve1(p - 1);
	}
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		for(int j = 0; j < 30; j ++){
			int p = (1 << j);
			if((a[i] & p) == p){
//				cout << 1;
				v[j].push_back(a[i]);
			}
//			else{
//				cout << 0;
//			}
		}
//		cout << '\n';
	}
	solve1(30);
	cout << ans;
	return 0;
}
//思路：按照从高到低的顺序分别看凑不凑的出来m个 
//100pts
//checked 
//O(log(a)n)
