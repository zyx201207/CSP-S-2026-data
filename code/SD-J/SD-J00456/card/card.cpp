#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5+10;
ll a[N] , s[N] , t[N];


int main(){
    freopen("card.in", "r",stdin); 
    freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	deque<ll> qu;
	ll m , n , x;
	cin >> n >> m; 
	for (ll i = 1;i <= n ; i++){
		cin >> x;
		a[i] = x;
		
	}  
	
	for (ll i = 1 ; i <= n ; i++){
		for (ll j = i ; j <= n ; j ++){
			if (s[a[j]] == 1){
				bool fg = false;
				while (!qu.empty()){
					if (qu.back() == a[j]) fg = true;
					s[qu.back()] = 0;
					qu.pop_back();
					if (fg) break;
				}
			}
			s[a[j]] = 1;
			qu.push_back(a[j]);
		}
		for (ll j = 1 ; j <= m ; j ++){
			if (s[j]){
				t[j] += 1; 
			}
			s[j] = 0;
		}
		while (!qu.empty()){
			qu.pop_front();
		}
	}
	for (ll j = 1 ; j <= m ; j ++){
		cout << t[j] << " ";
	}
	
	return 0;
}
