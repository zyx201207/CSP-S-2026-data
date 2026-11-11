#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, len[40], mnl;
ll a[200010], ans = 0;
ll pot[30];
bool inq[200010];
struct point {
	string s;
	ll len;
} na[200010]; 
void totwo(ll x, int i) {
	ll cnt = 0;
	while(x > 0) {
		bool md = x % 2;
		x /= 2;
		if(md) {
			na[i].s += "1";
		} else {
			na[i].s += "0";
		}
		cnt++;
	}
	na[i].len = cnt;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 
	pot[0] = 1;
	for(int i = 1; i <= 30; i++) {
		pot[i] = pot[i-1] * 2;
	}
	cin >> n >> m;
	// cout << len[19] << endl;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		totwo(a[i], i);
		len[na[i].len]++;
		for(int j = 0; j < na[i].len; j++) {
			if(na[i].s[j-1] == '1') {
				len[j]++;
				/*
				if(j == 19) {
					cout << i << endl;
				}
				*/
			}
		}
	}
	ll ans = 0;
	/*
	cout << endl; 
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) {
				continue;
			}
			ll tmp = a[i] & a[j];
			if(tmp == 262142) {
				cout << i << " " << j << endl; //1624 1461
			}
			cout << tmp << endl;
		}
	} 
	*/
	// cout << a[1624]  << " " << a[1461] << endl;
	// return 0;
	for(int i = 1; i <= 31; i++) {
		if(len[i] >= m) {
			mnl = max(mnl, i);
			// cout << len[i] << endl;
		}
	}
	// cout << endl;
	for(int i = 1; i <= n; i++) {
		if(na[i].s[mnl-1] == '1') {
			inq[i] = 1; 
		}
	}
	/*
	cout << endl;
	
	cout << na[196].len << endl << endl;
	cout << na[1215].s << " " << a[1215] << " " << na[1215].len << endl << endl;
	
	for(int i = 1; i <= n; i++) {
		if(na[i].len == 19) {
			cout << i << endl;
		}
	}
	cout << endl;
	
	
	cout << mnl << " " << pow(2, mnl - 1) << endl;
	cout << ans << endl << endl;
	
	/*
	cout << (a[ ] & a[ ]) << endl;
	cout << a[ ] << " " << a[ ] << endl;
	cout << na[ ].s << endl << na[ ].s << endl << endl;
	
	cout << a[1624]  << " " << a[1461] << endl;
	*/
	ans += pot[mnl - 1]; //不要忘了二进制下第几位是pow_of_two[len - 1]，要-1 
	for(int i = mnl-2; i >= 0; i--) { // string 从0开始存，要-1,然后第一位前面判过了，-2 
		int cnq = 0;
		for(int j = 1; j <= n; j++) {
			if(!inq[j]) {
				continue;
			}
			if(na[j].s[i] == '1') {
				cnq++;
			} 
		}
		if(cnq >= m) {
			ans += pot[i];
			for(int j = 1; j <= n; j++) {
				if(na[j].s[i] == '0' && inq[j]) {
					inq[j] = 0;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}

































//9:30 T3开始
//9:33 我去了这是不是DP啊 
//9:36 完了不会写，n^2暴力吧 
//9:37 不对，二进制位，我取尽量多个2^k的数 
//9:39 处理二进制！每个数转成二进制然后从大位往小位扫，看最大的有m个1的地方 
//9:58 写起来还是有点麻烦的 
//10:24 大样例3不对，其他都对了，太奇怪了 
//10:51 wocnb 我调出来了！手调2000n 2^20ai大样例！！！！！ 
//10:54 又都测了一遍，全a了，应该不会超时，准备打T4，T2先放着吧 
