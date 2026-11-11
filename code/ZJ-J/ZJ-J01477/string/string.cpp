#include <iostream>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define LL long long
#define int long long
using namespace std;

const int N = 2e5 + 10;
char ch[N];
int a[N], L[N], R[N];
int n;

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	LL len = 0;
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> ch[i];
		L[i] = R[i - 1] + 1;
		R[i] = R[i - 1] + a[i];
		len += a[i];
	}
	int mid;
	if (len % 2 == 0)
		mid = len / 2;
	else mid = len / 2 + 1; 
	int lll = mid;
		int sum = 0;
		for (int i = 1; i <= n; i++){
			sum += a[i];
			if (sum >= mid){
				mid = i;
				break;
			}
		}
		
		int l = 1, r = n;
		int tag_left = a[l], tag_right = a[r];
		int li = 0, lj = 0;
		LL ans = 0;
		while (l <= r && l != mid && r != mid){
			ans += min(tag_left, tag_right) * (ch[l] != ch[r]);
			if (tag_left < tag_right){
				tag_right -= tag_left;
				li += tag_left;
				lj += tag_left;
				l ++;
				tag_left = a[l];
			} else {
				tag_left -= tag_right;
				li += tag_right;
				lj += tag_right;
				r --;
				tag_right = a[r];
			}
//			cout << ans << '\n';
		}
		if (l == mid){
			tag_left = lll - L[mid] + (len % 2 == 0);
		}
		if (r == mid){
			tag_right = R[mid] - lll;
		}
//		cout << tag_left << " " << tag_right << '\n';
		bool f1 = 0, f2 = 0;
		while (l < mid){
			f1 = 1;
			ans += min(tag_left, tag_right) * (ch[l] != ch[r]);
			tag_right -= tag_left;
			l ++;
			tag_left = a[l];
//			cout << ans << '\n';
		}
		
		while (mid < r){
			f2 = 1;
			ans += min(tag_left, tag_right) * (ch[l] != ch[r]);
			tag_left -= tag_right;
			r --;
			tag_right = a[r];
		}
		
		cout << ans << '\n';
	
	return 0;
}