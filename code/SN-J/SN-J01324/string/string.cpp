#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
//void solve1(){
//	int mid = len + 1 >> 1, pos;
//	vector<array<int, 3>> v1, v2;
//	for(int i = 1; i <= n; i++){
//		if(l[i] <= mid && r[i] >= mid){
//			pos = i;
//		}
//	}
//	for(int i = 1; i < pos; i++){
//		v1.push_back({l[i], r[i], c[i]});
//	}
//	for(int i = n; i > pos; i--){
//		v2.push_back({l[i], r[i], c[i]});
//	}
//	if(l[pos] <= mid - 1) v1.push_back({l[pos], mid - 1, c[pos]});
//	if(r[pos] >= mid + 1) v2.push_back({mid + 1, r[pos], c[pos]});
////	cout << mid << " " << len << "\n";
////	for(auto i : v1) cout << i[0] << " " << i[1] << " " << i[2] << "\n";
////	for(auto i : v2) cout << i[0] << " " << i[1] << " " << i[2] << "\n";
//	
//	int len1 = 0, len2 = 0, lst1 = mid, lst2 = mid, lc1 = 0, lc2 = 0;
//	while(!v1.empty() && !v2.empty()){
//		int l1 = v1.back()[0], r1 = v1.back()[1], c1 = v1.back()[2];
//		int l2 = len - v2.back()[1] + 1, r2 = len - v2.back()[0] + 1, c2 = v2.back()[2];
////		cout << l1 << " " << r1 << " " << c1 << "\n"; 
////		cout << l2 << " " << r2 << " " << c2 << "\n"; 
//		if(len1 <= len2){
//			v1.pop_back();
//			len1 += r1 - l1 + 1;
//			ans += (r1 - lst2 + 1) * (lc2 != 0 && c1 != lc2);
//			lst1 = l1;
//			lc1 = c1;
//		}else{
//			v2.pop_back();
//			len2 += r2 - l2 + 1;
//			ans += (r2 - lst1 + 1) * (lc1 != 0 && c2 != lc1);
//			lst2 = l2;
//			lc2 = c2;
//		}
//	}
//	while(!v1.empty()){
//		int l1 = v1.back()[0], r1 = v1.back()[1], c1 = v1.back()[2];
////		cout << l1 << " " << r1 << " " << c1 << "\n"; 
//		v1.pop_back();
//		len1 += r1 - l1 + 1;
//		ans += (r1 - l1 + 1) * (lc2 != 0 && c1 != lc2);
//		lst1 = l1;
//		lc1 = c1;
//	}
//	while(!v2.empty()){
//		int l2 = len - v2.back()[1] + 1, r2 = len - v2.back()[0] + 1, c2 = v2.back()[2];
////		cout << l2 << " " << r2 << " " << c2 << " " << lst1 << "\n"; 
//		v2.pop_back();
//		len2 += r2 - l2 + 1;
//		ans += (r2 - l2 + 1) * (lc1 != 0 && c2 != lc1);
//		lst2 = l2;
//		lc2 = c2;
//	}
//	cout << ans;
//}
//void solve2(){
//	int mid = len >> 1, pos1, pos2;
//	vector<array<int, 3>> v1, v2;
//	for(int i = 1; i <= n; i++){
//		if(l[i] <= mid && r[i] >= mid){
//			pos1 = i;
//		}
//		if(l[i] <= mid + 1 && r[i] >= mid + 1){
//			pos2 = i;
//		}
//	}
//	for(int i = 1; i < pos1; i++){
//		v1.push_back({l[i], r[i], c[i]});
//	}
//	for(int i = n; i > pos2; i--){
//		v2.push_back({l[i], r[i], c[i]});
//	}
//	if(l[pos1] <= mid - 1) v1.push_back({l[pos1], mid - 1, c[pos1]});
//	if(r[pos2] >= mid + 2) v2.push_back({mid + 1, r[pos2], c[pos2]});
////	cout << mid << " " << len << "\n";
////	for(auto i : v1) cout << i[0] << " " << i[1] << " " << i[2] << "\n";
////	for(auto i : v2) cout << i[0] << " " << i[1] << " " << i[2] << "\n";
//	
//	int len1 = 0, len2 = 0, lst1 = mid, lst2 = mid, lc1 = 0, lc2 = 0;
//	while(!v1.empty() && !v2.empty()){
//		int l1 = v1.back()[0], r1 = v1.back()[1], c1 = v1.back()[2];
//		int l2 = len - v2.back()[1] + 1, r2 = len - v2.back()[0] + 1, c2 = v2.back()[2];
////		cout << l1 << " " << r1 << " " << c1 << "\n"; 
////		cout << l2 << " " << r2 << " " << c2 << "\n"; 
//		if(len1 <= len2){
//			v1.pop_back();
//			len1 += r1 - l1 + 1;
//			ans += (r1 - lst2 + 1) * (lc2 != 0 && c1 != lc2);
//			lst1 = l1;
//			lc1 = c1;
//		}else{
//			v2.pop_back();
//			len2 += r2 - l2 + 1;
//			ans += (r2 - lst1 + 1) * (lc1 != 0 && c2 != lc1);
//			lst2 = l2;
//			lc2 = c2;
//		}
//	}
//	while(!v1.empty()){
//		int l1 = v1.back()[0], r1 = v1.back()[1], c1 = v1.back()[2];
////		cout << l1 << " " << r1 << " " << c1 << "\n"; 
//		v1.pop_back();
//		len1 += r1 - l1 + 1;
//		ans += (r1 - l1 + 1) * (lc2 != 0 && c1 != lc2);
//		lst1 = l1;
//		lc1 = c1;
//	}
//	while(!v2.empty()){
//		int l2 = len - v2.back()[1] + 1, r2 = len - v2.back()[0] + 1, c2 = v2.back()[2];
////		cout << l2 << " " << r2 << " " << c2 << " " << lst1 << "\n"; 
//		v2.pop_back();
//		len2 += r2 - l2 + 1;
//		ans += (r2 - l2 + 1) * (lc1 != 0 && c2 != lc1);
//		lst2 = l2;
//		lc2 = c2;
//	}
//	cout << ans;
//}
int n, a[N], ans, tot;
char c[N];
char s[(int)1e7 + 5];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		for(int j = 1; j <= a[i]; j++){
			s[++tot] = c[i];
		}
	}
	int len = tot;
	if(len & 1){
		int mid = len + 1 >> 1;
		for(int i = 1; i < mid; i++){
			ans += (s[i] != s[len - i + 1]);
		}
		cout << ans;
	}else{
		int mid = len >> 1;
		for(int i = 1; i <= mid; i++){
			ans += (s[i] != s[len - i + 1]);
		}
		cout << ans;
	}
	return 0;
}
