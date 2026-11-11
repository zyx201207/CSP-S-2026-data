#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define __low lower_bound
#define __upp upper_bound
#define pii pair<int,int>
#define MP make_pair
#define fi first
#define se second
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e5+5;

int n;
ll a[N], m;
int ans;

struct pp{
	ll x, id;
};
deque<pp> q;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	ll sum = 0, maxx = 0;
	for(int r = 1, l = 1; r <= n; r++){
		sum += a[r];
		while(q.size() && q.back().x <= a[r]) q.ppb();
		q.pb({a[r], r});
		maxx = q.front().x;
		while(maxx * (r-l+1) - sum > m){
			sum -= a[l];
			if(q.front().id == l){
				q.ppf();
				maxx = q.front().x;
			}
			l++;
		}
		ans = max(ans, r-l+1);
	}
	cout << ans << "\n";
	
	return 0;
} 
