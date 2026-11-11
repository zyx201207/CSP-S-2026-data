#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n , m , a[N] , ans , p = (1 << 29);
vector<int> tmp , tmp1;
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		tmp.push_back(x);
	}
	for(int i = 0 ; i <= 29 ; i++){
		for(int i = 0 ; i < tmp.size() ; i++){
			if(tmp[i] & p){
				tmp1.push_back(tmp[i]);
			}
		}
		if(tmp1.size() >= m){
			ans |= p;
			tmp.clear();
			for(int i = 0 ; i < tmp1.size() ; i++){
				tmp.push_back(tmp1[i]);
			}
		}
		tmp1.clear();
		p >>= 1;
	}
	cout << ans;
	return 0;
}
