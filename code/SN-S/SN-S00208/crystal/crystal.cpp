#include <bits/stdc++.h>
using namespace std;
#define SHIH_SSU 0
typedef long long ll;
const int N = 5e5 + 5;

int n, Ans;
ll m, a[N], cst;
int num, cnt, tp = 0, bc = 1;
struct NODE{
	ll x;
	ll ct;
}b[N], c[N];

int main(){
//	freopen("crystal1.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	for(int i = 1; i <= n; i ++){
		if(b[cnt].x != a[i]) b[++ cnt] = {a[i], 1};
		else b[cnt].ct ++;
	}
	
	num = b[1].ct; Ans = max(Ans, num);
	c[++ tp] = b[1];
	for(int i = 2; i <= cnt; i ++){		// cong 2 kaishi
//		cout << num << ' ' << cst << '\n';
		if(num * (b[i].x - b[i - 1].x) <= m - cst){
			cst += num * (b[i].x - b[i - 1].x);
			num += b[i].ct; Ans = max(Ans, num);
			c[++ tp] = b[i];
		}
		else{
			while(tp >= bc){
				if(num * (b[i].x - b[i - 1].x) <= m - cst) break;
				ll D = b[i].x - b[i - 1].x;
				ll _D = b[i].x - c[bc].x;
				ll nd = num * D - m + cst;
				ll _cnt = nd / _D;
				if(_cnt * _D < nd) _cnt ++;
				if(_cnt <= c[bc].ct){
					num -= _cnt; cst -= _cnt * (b[i - 1].x - c[bc].x);
					c[bc].ct -= _cnt;
					if(! c[bc].ct) bc ++;
					break;
				}
				else{
					_cnt = c[bc].ct;
					num -= _cnt; cst -= _cnt * (b[i - 1].x - c[bc].x);
					c[bc].ct -= _cnt;
					if(! c[bc].ct) bc ++;
				}
			}
			cst += num * (b[i].x - b[i - 1].x);
			num += b[i].ct; Ans = max(Ans, num);
			c[++ tp] = b[i];
		}
	}
	
	cout << Ans << '\n';
	
	return SHIH_SSU;
}
