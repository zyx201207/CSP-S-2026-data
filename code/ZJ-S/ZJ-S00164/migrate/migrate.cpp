/*
	Name: migrate
	Copyright: CSP-S
	Author: CLP666
	Date: 31/10/26 18:25
	Description: 
*/
#include <bits/stdc++.h>
#define rks register
using namespace std;
typedef long long ll;
const ll MAXN = 2e6+5;
//const ll MOD = ;
ll c, t, n, d;
ll x[MAXN], dis[MAXN], num[MAXN];
               
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll cnt, ans;
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(rks ll i = 1; i <= n; i++)
			cin >> x[i];
		for(rks ll i = 1; i < n; i++){
			ans = cnt = 0;
			memset(dis, -1, sizeof(dis));
			memset(num, 0, sizeof(num));
			dis[1] = 0;
			for(rks ll j = i; j <= n-d; j++){
				for(rks ll k = j; k <= j+d; k++){
					if(dis[k] > dis[j]+1)
						dis[k] = dis[j]+1, num[k] = 0;
					else if(dis[k] == dis[j]+1)
						num[k]++;
				}
			}
			for(rks ll j = i+1; j <= n; j++)
				if(num[j] == 2)
					cnt++;
		}
		cout << ans << endl;
	}
	return 0;
}

