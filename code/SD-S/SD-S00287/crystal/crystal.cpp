#include<bits/stdc++.h>
#define int long long
#define FOR(n, x) for (n = 0; n < x; n++)
using namespace std;
const int N = 5e5+1;
int a[N];
int dff[N];
int pre[N];
bool cmp(int a, int b){
	return a > b;
}
int cst(int l, int r){
	return pre[r]-pre[l]-(r-l)*dff[l];
}
int mid(int l, int r){
	return ((l+r+1)>>1);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
//	cerr << "INputed\n";
	sort(a+1, a+n+1, cmp);
	int ree = a[1];
	for (int i = 2; i <= n; i++) dff[i] = ree-a[i], pre[i] = pre[i-1]+dff[i];
//	FOR(i, n) cout << pre[i] << endl;
	//二分可能的答案 
	int l = 0, r = n-1;
	int ans = -1e9;
//	if (cst(0, n-1) <= m) return cout << n << endl, 0;
	for (int i = 1; i <= n; i++){
		int premax = n;
//		cerr << i << endl;
		//二分查找可能的答案 
		int maxx = n, minn = i;
//		cout << r << endl;
		while (!(cst(i, maxx) <= m && cst(i, maxx+1) > m)){
			
/*
转换一下问题：
对于i~n，求一个最大的r满足cst(i, r) <= m 
二分r，如果a[r] > m then r移动到r与上一个a[r]>n的r 
如果a[r]<=m then r 移动到r与上一个r的中间 
*/
			int j = cst(i, maxx);
			if (j > m){
				premax = maxx;
				maxx = mid(maxx, minn);
			} else {
				if (maxx == n) break;
				maxx = mid(maxx, premax);
			}
//			cout << maxx << ' ' << minn << endl;
//			pastr = r;
//			prer = r;
		}
		if (maxx-i+1 > ans) ans = maxx-i+1;
//		ans = max(ans, minn-i+1);
//		cout << ans << endl; 
		/*
		如果当前的l 
		*/ 
	}
	//它已经被 
	cout << ans << endl;
	return 0;
}
//SD-S00287穆昕雨 
