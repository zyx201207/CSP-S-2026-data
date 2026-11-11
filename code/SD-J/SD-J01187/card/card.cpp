#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 3e5 + 10;
ll n, m;
ll a[N];
ll c[N];
ll ans[N];

bool check(ll x, ll t){
	for(int i = 1; i<= t; i++){
		if(c[i] == x) return false;
	}
	return true;
}

ll cl(int k, int j){
	ll o = k - j;
	for(int i = k=1; i<= j ; i++){
		c[i] = 0;
	}
	return o;
}

int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	cout << "hi\n";
	cin >> n >> m;
//	cout << "uuu\n";
	for(int i = 1; i<= n ; i++){
		cin >> a[i];
//		cout << "\n\n"s << i << "\n\n";
	}
//	cout << "\n\n---\n\n---\n\n=========\n";
	for(int i = 1; i <= m; i++){
		ll t = 0;
		for(int j = i; j<= n ; j++){
//			cout << "--";
			if(check(a[j], t)){
				t++;
				c[t] = a[j];
//				cout << "YES   " << a[j] << "  \n";
			}else{
				for(int k = j; k >= i; k--){
					if(c[k] == a[j]){
//						cout << "no   " << c[k] << "   \n";
						t -= cl(k, j);
						c[t] = a[j];
					}
				}
			}
			
//		cout << " \n\n";
//		for(int i = 1; i<= t; i++){
//			cout << c[i] << " ";
//		} 
		}
//		cout << "\n\n====flag====\n\n";
		for(int j = i; j<= t; j++){ 
//			cout << "---\n";
//			cout << c[j] << "\n";
			ans[c[j]] ++;
		}
	}
	
	for(int i = 1; i<= m; i++){
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}
