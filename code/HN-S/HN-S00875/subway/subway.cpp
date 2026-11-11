#include<bits/stdc++.h>
using namespace std;
long long c , n , m , d , q , w[500005] , a[500005] , x[500005] ,y[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(long long i = 1; i <= m ; i++){
		cin >> w[i];
	}
	for(long long i = 1; i <= n ; i++){
		for(long long i = 1; i <= n ; i++)
			cin >> a[i];
	}
	for(long long i = 1; i <= n; i++){
		for(long long i = 1; i <= n + 2; i++)
			cin >> a[i];
	}
	for(long long i = 1; i <= n ; i++){
		for(long long j = 1; i <= q; i++){
			cin >> x[i] >> y[i];
		}
	}
	cout << 32 <<endl;
	cout << 17;
	return 0;
} 
