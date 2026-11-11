#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pb push_back
#define _1 first
#define _2 second
using namespace std;

#define int ll
const int N = 5e5 + 5;
const ll inf = 1e12; 
int n, ans = 1;
ll m, a[N], diff[N], sum[N];
pair<int, ll> t[N];

int get(int x){
	int w = lower_bound(a + 1, a + n + 1, x) - a - 1;
	return w;
}

bool check(int l, int r){
	ll tmp = abs(diff[r] - abs(diff[l]) - (l - 1) * (a[r] - a[l]));
//	cout << l << " " << r << " " << tmp << endl;
	return tmp <= m;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	memset(t, 0, sizeof 0), diff[0] = 0;
	for(int i = 1; i <= n; i++)
		t[get(a[i])]._1++, t[get(a[i])]._2 = a[i];
	for(int i = 2; i <= n; i++)
		diff[i] = diff[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
//	for(int i = 1; i <= n; i++)
//		cout << diff[i] << " " << sum[i] << endl;
	for(int i = 1; i <= n; i++){
		if(a[i - 1] == a[i]) continue;
		int x = get(a[i]), res = t[x]._1, tmp = i;
		int l = 1, r = i - 1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(mid, i)) tmp = mid, r = mid - 1;
			else l = mid + 1;
		}
//		cout << i << " " << tmp << endl;
		res += (i - tmp);
		ans = max(ans, res);
	}
	cout << ans << endl;
	return 0;
}
/*
input:
5 8
-3 -1 2 2 7
output:
4
*/
