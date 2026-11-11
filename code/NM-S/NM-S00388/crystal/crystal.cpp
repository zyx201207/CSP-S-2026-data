#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5+5;

ll n, m;
ll a[N];
vector <ll> ans;
ll k;

void func(){
	for(ll i = n - 1; i >= 0; i--){
		ll m1 = m, num = 1;
		for(ll j = i - 1; j >= 0; j--){
			if(a[j] == a[i]){
				num++;
				continue;
			}
			if(a[i] - a[j] <= m1){
				m1 -= a[i] - a[j];
				num++;
			}
			else break;
		}
		ans.push_back(num);
	}
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	for(ll i = 0; i < n; i++){
		cin>>a[i];
	}
	
	sort(a, a + n);
	
	func();
	sort(ans.begin(), ans.end());
	
	k = ans.size();
	cout<<ans[k - 1]<<endl;
	
	return 0;
}
