#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 +5;

ll n, m, ans = 1, s = 0;
ll a[N];
queue<ll> q;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		if(i == 1){
			q.push(a[i]);
			s++;
		}else{
			while(!q.empty() && (a[i] - a[i - 1]) * s > m){
				m += a[i - 1] - q.front();
				q.pop();
				s--;
			}
			m -= (a[i] - a[i - 1]) * q.size();
			q.push(a[i]);
			s++;
			ans = max(s, ans);
		}
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
6 4
1 3 5 6 7 8
6 5
1 2 3 4 5 6
*/
