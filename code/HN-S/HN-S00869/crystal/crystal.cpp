#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 5e5 + 5;
const ll INF = -0x7fffffff; 
ll n, m, cost, ans, cnt;
ll a[N];
/*
我想过我终会退役， 
但没想到会这么快 

在故事的尽头，人们总会忍不住回忆故事的开始 
——R_C_O_R -Oct 31st 
*/
inline void solve(int s){
	priority_queue<ll> q;		//大根堆 
	cost = 0;
	while(!q.empty()){ q.pop(); }
	q.push(0);
	for(int i = s - 1; i >= 1; i--){
		ll diff = abs(a[s] - a[i]);
		if(diff <= m - cost){		//能加就先往里加  diff + cost <= m
			q.push(diff);
			cost += diff;
		}else{
			break;
		}
	} 
	for(int i = s + 1; i <= n; i++){
		ll diff = abs(a[i] - a[s]);
		if(diff <= m - cost){		//能加就先往里加  diff + cost <= m
			q.push(diff);
			cost += diff;
			continue; 
		}
		if(diff > m - cost && cost - q.top() + diff <= m){		//加不下了,但可以优化 
			cnt = q.top();
			q.pop();
			q.push(diff);
			cost = cost - cnt + diff;
			if(cost >= m) break;
		}else{
			break;
		}
	} 
	ans = max(ans, (ll)q.size());
	return;
}

inline ll read(){
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); }
	return x * f;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	n = read(); m = read(); ans = INF;
	for(int i = 1; i <= n; i++){
		a[i] = read();
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++){
		solve(i);
	}
	cout << ans;
	
	return 0;
} 






