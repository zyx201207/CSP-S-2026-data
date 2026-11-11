#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define repb(i, a, b) for(int i = (a); i >= (b); --i)

typedef long long ll;
const int N = 2e5 + 5;

int n, m;
vector<int> a;
vector<int> b;

bool solve(int x){
	b.clear();
	for(int p : a){
		if(p & (1 << x)) b.emplace_back(p);
	}
	if((int)b.size() >= m){
		a = b;
		n = b.size();
		return true;
	}
	else{
		return false;
	}
}

int ans = 0;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	rep(i, 1, n){
		int x;
		cin >> x;
		a.emplace_back(x);
	}
	
	int i = 30;
	while(i >= 0){
		ans |= solve(i) << i;
		i--;
	}
	
	cout << ans << '\n';
	
	return 0;
}