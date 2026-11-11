#include <bits/stdc++.h>
#define ll long long
#define prc pair<ll, char>
using namespace std;

ll n, ans=0;
deque<prc> str;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// input
	cin >> n;
	ll tmp;
	char tc;
	cin >> tmp >> tc;
	str.push_back({tmp, tc});
	for(int i=1; i<n; i++){
		cin >> tmp >> tc;
		if(str.back().second == tc){
			tmp += str.back().first;
			str.pop_back();
		}
		str.push_back({tmp, tc});
	}
	
	// solve
	while(int(str.size()) > 1){
		prc frt=str.front();
		prc bk=str.back();
		str.pop_front();
		str.pop_back();
		if(frt.second != bk.second){
			ans += min(frt.first, bk.first);
		}
		if(frt.first > bk.first){
			frt.first -= bk.first;
			str.push_front(frt);
		}else if(frt.first < bk.first){
			bk.first -= frt.first;
			str.push_back(bk);
		}
	}
	
	// print
	cout << ans << '\n';
	
	// end
	return 0;
}
