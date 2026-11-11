#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200005], t, ans;
struct ss{
	int a[100], len, tot;
}p[200005];
bool cmp(ss l, ss r){
	if(l.len != r.len){
		return l.len > r.len;
	}
	else{
		for(int i = 1;i <= l.len;i++){
			if(l.a[i] != r.a[i]){
				return l.a[i] > r.a[i];
			}
		}
		return l.len >= r.len;
	}
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> p[i].tot;
		int k = p[i].tot;
		t++;
		while(k != 0){
			p[t].a[++p[t].len] = k % 2;
			k /= 2;
		}
	}
	sort(p + 1, p + t + 1, cmp);
	ans = p[1].tot;
	for(int i = 2;i <= m;i++){
		ans = ans & p[i].tot;
	}
	cout << ans;
	return 0;
}
