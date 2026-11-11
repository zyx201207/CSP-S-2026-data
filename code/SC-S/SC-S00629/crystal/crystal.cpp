#include<bits/stdc++.h>
#define _for(i, a, b) for(int i = a; i <= b; ++i)
#define for_(i, a, b) for(int i = a; i >= b; --i)
using namespace std;
const long long N = 5e5 + 5;
long long n, m, a[N], s1[N], s2[N], l, ans, cnt, t, idx;
map<long long, long long> mp;
struct node{
	long long x, y;
}p[N];
bool cmp(node a, node b){
	return a.x < b.x;
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	_for(i, 1, n){
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	for(auto i : mp){
		p[++idx].x = i.first;
		p[idx].y = i.second;
	}
	sort(p + 1, p + idx + 1, cmp);
	l = 1;
	_for(i, 1, idx){
		cnt += t * (p[i].x - p[i - 1].x);
		t += p[i].y;
		while(cnt > m){
			cnt -= p[i].x - a[l];
			l++, t--;
		}
		ans = max(ans, t);
	}
	cout << ans;
	return 0;
}