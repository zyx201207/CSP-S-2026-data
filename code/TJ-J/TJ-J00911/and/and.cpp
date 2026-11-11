#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ans, sum, mx, pos;//当前还剩的个数 
struct node{
	int x, p;//p=0未淘汰 p=1淘汰 
}a[200005];
bool cmp(node l, node r){
	if(l.p != r.p)
		return l.p< r.p;
	return ((l.x >> pos) & 1) > ((r.x >> pos) & 1);
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	sum = n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].x;
		a[i].p = (int) 0;
		mx = max(mx, a[i].x);
	}
	pos = __lg(mx) + 1;
	sum = n;
	for(; pos >= 0; pos--){
		sort(a + 1, a + sum + 1, cmp);
		int i = 1, cnt = 0;//记录一下第pos位是1的个数 
		while(a[i].p == 0 && ((a[i].x >> pos) & 1) == 1){
			cnt += 1;
			i++;
		}
		if(cnt == m){
			break;
			sum = cnt;
		}
		if(cnt > m){
			while(i <= sum){
				a[i].p = 1;
				i++;
			}
			sum = cnt;
		}
	}
	int ans = a[1].x;
	for(int i = 1;i <= m;i++)
		ans = ans & a[i].x;
	cout << ans;
	return 0;
}
