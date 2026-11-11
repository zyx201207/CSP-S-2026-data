#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n, premid, ans = 0;
ll a[500010];
ll m, use = 0;
bool chgl = 0;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	int l = 1, r = 1;
	//r - l + 1是有几个数 
	//int bnt = 0;
	//for(int i = 112858; i <= 428132; i++) {
	//	bnt += a[428133] - a[i];
	//}
	//cout << bnt << endl << (bnt > m) << endl;
	while(r <= n) {
		int mid = r;
		if(r < l) {
			r = l;
			use = 0;
			ans = max(ans, 1);
			continue;
		}
		if(l == r) {
			use = 0;
			ans = max(ans, 1);
			r++;
			continue;
		} else {
			if(chgl) {
				// cout << "old:" << use << " ";
				use = use - (a[mid] - a[l-1]);
				// cout << "new:" << use << " ";
				chgl = 0;
			} else {
				//use = (mid - l) * (a[mid] - a[premid]) + use + (a[r] - a[mid]) + (r - mid) * (a[mid] - a[premid]); wrong 
				use = (r - l) * (a[mid] - a[premid]) + use;
			}
			// cout << l << " " << r << " " << use << " " << ans << " " << chgl << " " << m << endl;
			if(use > m) {
				l++;
				chgl = 1;
				premid = mid;
				continue;
			} else {
				ans = max(ans, r - l + 1);
			}
		}
		/* 
		if(ans == r - l + 1) {
			cout << l << " " << r << " " << ans << endl; //112858 428133 
		} */ 
		r++;
		premid = mid;
	}
	// mid = (n >> 1) + 1;
	// cout << "ans:" << ans << endl;
	// cout << mid << endl;
	// cout << "a[i]:" << " ";
	/*
	for(int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl << "mid:" << mid << endl;
	cout << "a[mid]:" << a[mid] << endl;
	*/
	/*
	for(int i = 1; i <= n; i++) {
		nd[i] = abs(a[mid] - a[i]);
		if(!nd[i]) {
			ans++;
		}
	}
	int l = mid, r = mid;
	while(l >= 1 && r <= n) {
		if(l-1 >= 1) {
			if(nd[l-1] <= nd[r+1]) {
				ans++;
				m -= nd[l-1];
				// cout << "ans is adding, l:" << l << " " << "need:" << nd[l-1] << " m:" << m << " other one(right side):" << r << " need of right:" << nd[r+1] << endl;
				l--;
			} else if(nd[l-1] > nd[r+1]) {
				ans++;
				m -= nd[r+1];
				// cout << "ans is adding, r:" << r << " " << "need:" << nd[r+1] << " m:" << m << " other one(left side):" << l << " need of left:" << nd[l-1] << endl;
				r++;
			}
		} else if(r+1 <= n) {
			if(nd[l-1] >= nd[r+1]) {
				ans++;
				m -= nd[r+1];
				// cout << "ans is adding, r:" << r << " " << "need:" << nd[r+1] << " m:" << m << " other one(left side):" << l << " need of left:" << nd[l-1] << endl;
				r++;
			} else if(nd[l-1] < nd[r+1]) {
				ans++;
				m -= nd[l+1];
				// cout << "ans is adding, l:" << l << " " << "need:" << nd[l-1] << " m:" << m << " other one(right side):" << r << " need of right:" << nd[r+1] << endl;
				l--;
			} 
		} else {
			// cout << "break" << endl;
			break;
		}
		if(m < 0) {
			ans--;
			// cout << "done,m:" << m << " " << "ans:" << ans << endl;
			break;
		}
	} */
	printf("%d", ans);
	return 0;
} 






//15:10 I found the problem of my code, the problem was that we need to use dp not tanxin to do this problem. 
//15:14 Maybe not dp is ok, I sort a so maybe I cantry to use l and r to do this problem
//15:20 怎么越写越像莫队啊 
//15:29 式子导出来了,终于 准备开写(\- -/) 
//16:01 woc理解错题意了,不过好像变简单了,原来的式子改一改就可以用了 
//16:15 哈哈哈哈哈！小爷我成啦！！！！！CCFRP++！！！CCF太好了！！！！！！！！！！！ 
//18:17 靠，最后一个大样例怎么不过了 
