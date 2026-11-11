#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
typedef long long ll;
struct node{
	int l , r;
};
ll c  , t , n , d , ans , x[N];
vector<node> v;
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> c >> t;
	while(t--){
		ans = 0;
		v.clear();
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i++){
			cin >> x[i];
		}
		int L = 1 , R = 1 , lr = 0 , ll;
		while(R <= n && x[R] - x[L] <= d) R++;
		R--;
		ll = L;
		lr = R;
		v.push_back((node){ll , lr});
		while(R <= n){
			while(R <= n && x[R] - x[L] <= d) R++;
			while(L <= n && x[R] - x[L] > d) L++;
			while(R <= n && x[R] - x[L] <= d) R++;
			R--;
			if(L == lr) v.pop_back();
			else ll = L;
			lr = R;
			v.push_back((node){ll , lr});
			R++;
		}
		int tmp = v.size() - 1;
		L = -1 , R = 1;
		while(R <= tmp){
			L++;
			R = max(R , L + 1);
			while(R <= n && v[L].r - v[R].l > 1) R++;
			if(R > tmp) break;
			if(v[L].r - v[R].l == 1) ans += 1ll * (v[L + 1].l - v[L].l) * (v[R].r - v[R - 1].r);
		}
		cout << ans << endl;
	}
	return 0;
}
