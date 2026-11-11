#include <bits/stdc++.h>

#define multicase() int t;cin>>t;while(t--)

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

void fast_io(){
	ios::sync_with_stdio(0);
	cin.tie(0) ,cout.tie(0);
}

const ll kMaxN = 5007;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll F[kMaxN][kMaxN];
ll G[kMaxN][kMaxN];
ll pos[kMaxN];

ll c;

ll n , d;

void clear(){
	for(int i = 0 ; i <= n ; i++) {
		for(int j = 0 ; j <= n ; j++) F[i][j] = inf , G[i][j] = inf;
	}
}

const ll kMaxNA = 2e6 + 7;

ll pA[kMaxNA];

void solveA(){
	cin>>n>>d;
//	cout<<"ohno";
	for(int i = 1 ; i <= n ; i++) cin>>pA[i];
	ll j = 2;
	for(j ; j <= n ; j++){
		if(pA[j] - pA[1] > d) break; 
	}
	while(pA[j] - pA[1] > d) j--;
	ll len = j - 1;
	if(len <= 1) return void(cout<<0);
	cout<<max(0LL , n - 2 * len + 1);
	return;
}

void solve(){
	if(c >= 11 && c <= 12) return solveA();
	cin>>n>>d;
	clear();
	for(int i = 1 ; i <= n ; i++) {
		cin>>pos[i];
		for(int j = i - 1 ; j >= 1 ; j--) {
			if(pos[i] - pos[j] <= d) F[i][j] = F[j][i] = 1 , G[i][j] = G[j][i] = 1; 
		}
	}
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(F[i][k] + F[k][j] < F[i][j]){
					F[i][j] = F[i][k] + F[k][j];
					G[i][j] = G[i][k] * G[k][j];
				}else if(F[i][k] + F[k][j] == F[i][j]){
					G[i][j] += G[i][k] * G[k][j];
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 1 ; i <= n ; i++){
		for(int j = i - 1 ; j >= 1 ; j--){
			if(F[i][j] != inf && G[i][j] == 2){
				ans++;	
			}
		}
	}
	cout<<ans;
}

int main(){
	fast_io();
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin>>c;
	multicase(){
		solve();
		cout<<"\n";
	}
	return 0;
}

