#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int N = 5e5 + 10;
int a[N], n, m;
int cnt[N];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	map<int, int> cnt;
	
	for (int i = 1; i <= n; i++){
		vector<int> vec;
		map<int, int> mp;
		
		for (int j = i; j <= n; j++){
			if (mp[a[j]]){
				while (vec.back() != a[j]){
					mp[vec.back()] = 0;
					vec.pop_back();
				}
				vec.pop_back();
			}
			mp[a[j]] = 1;
			vec.push_back(a[j]);
		}
		
		for (auto j: vec){
			cnt[j] ++;
		}
		
//		cout << '\n';
		
	}
	
	for (int i = 1; i <= m; i++){
		cout << cnt[i] << " ";
	}
	
	return 0;
}