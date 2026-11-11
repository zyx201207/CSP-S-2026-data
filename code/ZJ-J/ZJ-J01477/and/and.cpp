#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define LL long long
using namespace std;

const int N = 2e5 + 10;
int a[N];
int n, m;
vector<int> vec;
bool check(int bit){
	vector<int> lll;
	for (auto i: vec){
		if ((i >> bit) & 1){
			lll.push_back(i);
		}
	}
	
	if (lll.size() >= m){
		vec = lll;
		return 1;
	}
	return 0;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	fast;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		vec.push_back(a[i]);
	}
	for (int i = 29; i >= 0; i--){
		if (check(i)){
			
		}
	}
	LL ans = (1 << 30) - 1;
	for (int i = 0; i < m; i++){
		ans &= vec[i];
	}
	
	cout << ans << '\n';
	
	return 0;
}