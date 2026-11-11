#include <bits/stdc++.h>
using namespace std;

const long long M = 5e5 + 10 , N = 510;

struct node{
	long long to , w1 , w2;
};

long long c , n , m , d , q;
long long w[M] , k[510] , t[N][5] , a[N][5];
bool flag1 = true;
vector<node> dist(M);

void solve1(){
	for(long long i = 1 ; i <= n ; i++){
		if(k[i] == 2){
			dist[a[i][1]].to = a[i][2];
			dist[a[i][1]].w1 = t[i][1];
			dist[a[i][1]].w2 = t[i][2];
		}
	}
	while(q--){
		long long l , r , ans = 0ll;
		cin >> l >> r;
		if(l > r)
			swap(l , r);
		ans += (w[l] + w[r]);
		long long tmp = l;
		while(true){
			if(dist[tmp].to == r){
				ans += dist[tmp].w1 + dist[tmp].w2;
				tmp = dist[tmp].to;
				break;
			}else{
				ans += dist[tmp].w1 + dist[tmp].w2;
			}
		}
		ans += dist[tmp].w1 + dist[tmp].w2;
		cout << ans << endl;
	}
}

void solve2(){
	while(q--){
		int l , r;
		cin >> l >> r;
		cout << w[l] + w[r] << endl;
	}
}

int main(){

	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(long long i = 1 ; i <= m ; i++)
		cin >> w[i];
	for(long long i = 1 ; i <= n ; i++){
		cin >> k[i];
		for(long long j = 1 ; j <= k[i] ; j++){
			cin >> a[i][j] >> t[i][j];
		}
		if(k[i] > 2){
			flag1 = false;
		}
	}
	
	if(flag1){
		solve1();
	}else{
		solve2();
	}
	
	return 0;
}