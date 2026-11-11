#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N = 500001;
int n, id;
ll m, a[N], b[N], sum, ans;
ll calc(int mid){
	ll m1 = m, res = 0;
	fill(b, b + N, 1ll * 1e12 * 5);
	b[0] = -1ll * 1e12 * 5;
	for(int i = 1; i <= n; i++){
		b[i] = a[i];
	}
	for(int rp = mid + 1, rl = mid - 1; rp <= n || rl >= 1; ){
		if(1ll * b[rp] - b[mid] < 1ll * b[mid] - b[rl]){
			m1 -= 1ll * b[rp] - b[mid];
			if(m1 >= 0) b[rp++] = b[mid];
//			cout << i << " r++\n";
		}
		if(1ll * b[rp] - b[mid] >= 1ll * b[mid] - b[rl]){
			m1 -= 1ll * b[mid] - b[rl];
			if(m1 >= 0) b[rl--] = b[mid];
//			cout << j << " l--\n";
		}
		if(m1 <= 0) break;
	}
	for(int i = 0; i <= n + 1; i++){
//		cout << (int)b[i] << ' ';
//		if(i == 0 || i == n) cout << ' ';
		if(b[i] == b[mid]){
			res++;
			cout << i << ' ';
		}
	}
	cout << '\n';
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	fill(a, a + N, LLONG_MAX);
	cin >> n >> m;
	int m1 = m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
		sum += a[i];
	}
	long double x = 1.0 * sum / n;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		if(a[i] > x){
			id = i;
			break;
		}
	}
	if(1.0 * a[id] - x < 1.0 * x - a[id - 1]) id--;
//	cout << id << '\n';
	ll tmp = calc(id);
	cout << tmp << '\n';
	ans = max(ans, tmp);
	id = (n + 1) / 2;
//	cout << id << '\n';
	tmp = calc(id);
	cout << tmp << '\n';
	ans = max(ans, tmp);
	ll maxx = 0;
	for(int i = 1, cnt = 0; i <= n; i++){
		while(a[i] == a[i + 1]){
			cnt++;
			i++;
		}
		if(cnt > maxx){
			maxx = cnt;
			id = i;
		}
	}
//	cout << id << '\n';
	tmp = calc(id);
	cout << tmp << '\n';
	ans = max(ans, tmp);
	cout << ans;
	return 0;
}
// 5 5
// 1 2 4 8 9 inf	
