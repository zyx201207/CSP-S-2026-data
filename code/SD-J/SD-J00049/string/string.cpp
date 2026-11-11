//#include<bits/stdc++.h>
//#define int long long
//using namespace std ;
//
//vector<int> num ; // 个数 
//vector<int> ch ; // 字符
//vector<int> head ; // 首地址
//vector<int> _end ; // 尾地址
//vector<vector<int>> e_ch ;// 每种字母的总数
//vector<int> sum ; // 所有字母的总数 
//
//
//signed main(){
////	freopen("string4.in" , "r" , stdin) ;
//	freopen("in.txt" , "r" , stdin) ;
////	freopen("string4.in" , "r" , stdin) ;
////	freopen("string.in" , "r" , stdin) ;
////	freopen("string.out" , "w" , stdout) ;
//	ios::sync_with_stdio(false) ;
//	cin.tie(nullptr) ;
//	int n ;
//	cin >> n ;
//	
//	num.assign(n + 1 , 0) ;
//	ch.assign(n + 1 , 0) ;
//	head.assign(n + 1 , 0) ;
//	_end.assign(n + 1 , 0) ;
//	_end[0] = -1 ;
//	e_ch.assign(n + 1 , vector<int>(26 + 3 , 0) ) ;
//	sum.assign (n + 1 , 0) ; 
//	int sum_size = 0 ;
//	
//	for (int i = 1 ; i <= n ; ++ i){
//		int a ;
//		char c ;
//		cin >> a >> c ;
//		int _ch = c - 'a' + 1 ;
//		num[i] = a ;
//		ch[i] = _ch ;
//		
//		head[i] = _end[i - 1] + 1 ;
//		_end[i] = head[i] + a - 1 ;
//		e_ch[i][_ch] = a ;
//		for (int j = 1 ; j <= 26 ; ++ j){
//			e_ch[i][j] += e_ch[i - 1][j] ;
//		}
//		sum[i] = sum[i - 1] + a ;
//		sum_size += a ; 
//	} 
//	int ans = 0 ;
//	
//	
//	for (int i = 1 ; i <= n ; ++ i)
//		cout << num[i] << " " ;
//	cout << "\n" ;
//	for (int i = 1 ; i <= n ; ++ i)
//		cout << ch[i] << " " ;
//	cout << "\n" ;
//	for (int i = 1 ; i <= n ; ++ i)
//		cout << head[i] << " " ;
//	cout << "\n" ;
//	for (int i = 1 ; i <= n ; ++ i)
//		cout << _end[i] << " " ;
//	cout << "\n" ;
//	cout << "\n" ;
//	for (int j = 1 ; j <= 26 ; ++ j){
//		for (int i = 1 ; i <= n ; ++ i)
//			cout << e_ch[i][j] << " " ;
//		cout << "\n" ;
//	}
//	cout << "\n" ;
//	for (int i = 1 ; i <= n ; ++ i)
//		cout << sum[i] << " " ;
//	cout << "\n\n\n" ;
//	
//	for (int i = 1 ; i <= n ; ++ i){ // 记得提前退出 
//		int l = head[i] ;
//		int r = _end[i] ;
//		if (l >= sum_size / 2) break ;
////		if (r >= sum_size / 2 + 1) r = sum_size / 2 + 1 ;
//		if (r >= sum_size / 2) r = sum_size / 2 ;
//		// 目标区间 
//		int _l = sum_size - 1 - r ; 
//		int _r = sum_size - 1 - l ;
////		cout << _l << " " << _r << "\n" ;
//		// 二分找小于等于_l ， 大于等于 _r 的数的下标 
//		int lo = 1 ;
//		int hi = n ;
//		int ans1 = -1 ;
//		
//		while (lo <= hi){
//			int mid = lo + (hi - lo) / 2 ;
//			if (head[mid] <= _l){
//				ans1 = mid ;
//				lo = mid + 1 ;
//			} else hi = mid - 1 ;
//		}
//		
//		lo = 1 ;
//		hi = n ;
//		int ans2 = -1 ;
//		while (lo <= hi){
//			int mid = lo + (hi - lo) / 2 ;
//			if (_end[mid] >= _r){
//				ans2 = mid ;
//				hi = mid - 1 ;
//			} else lo = mid + 1 ;
//		} 
//		
//		if (ans1 == ans2){
//			cout << "ans1 = " << ans1 << "\n" ;
//			cout << "相等\n" ;
//			if (ch[ans1] != ch[i]){
//				ans += _r - _end[ans1] + 1 ;
////				cout << "ans +=" << num[ans1] << "\n\n" ;  
//			}
//			continue ;
//		}
//		if (ch[ans1] != ch[i] && head[ans1] != _l){
//			ans += _end[ans1] - _l + 1 ;
//			cout << "ans += " << _end[ans1] - _l + 1 << "\n" ;
//		}
//		if (ch[ans2] != ch[i] && _end[ans2] != _r){
//			ans += _r - head[ans2] + 1 ;
//			cout << "ans += " << _r - head[ans2] + 1 << "\n" ;
//		}
//		cout << "_end[ans2] = " << _end[ans2] << " " ;
//		cout << "_r = " << _r << "\n" ;
//		
//		int left ;
//		int right ;
//		if (_end[ans1] != _l) left = ans1 ;
//		else left = ans1 + 1 ;
//		if (_end[ans2] != _r) right = ans2 - 1 ;
//		else right = ans2 ;
//		
//		
//		cout << "left = " << left << " right = " << right << "\n" ;
//		if (left <= right){
//			ans += (sum[right] - sum[left - 1]) - 
//				(e_ch[right][ch[i]] - e_ch[left - 1][ch[i]]) ;
//			cout << "总 : " << (sum[right] - sum[left - 1]) << "\n" ;
//			cout << "不用修改： " << (e_ch[right][ch[i]] - e_ch[left - 1][ch[i]]) << "\n" ; 
////			ans += (sum[ans2 - 1] - sum[ans1]) - 
////				(e_ch[ans2 - 1][ch[i]] - e_ch[ans1][ch[i]]) ;
////			cout << "ans += " << (sum[ans2 - 1] - sum[ans1]) - 
////				(e_ch[ans2 - 1][ch[i]] - e_ch[ans1][ch[i]]) << "\n" ;
//		}
//		cout << "ans = " << ans << "\n" ;
//		cout << "l = " << l << "\n" ;
//		cout << "r = " << r << "\n" ;
//		cout << "_l = " << _l << " " ;
//		cout << "_r = " << _r << "\n" ;
//		cout << "ans1 = " << ans1 << " " ;
//		cout << "ans2 = " << ans2 << "\n" ;
//		cout << "\n\n" ;
//	}
//	cout << ans ;
//	return 0 ;
//}


#include<bits/stdc++.h>
#define int long long 
using namespace std; 

signed main(){
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(nullptr) ;
	int n ;
	cin >> n ;
	string sum ;
	while (n --){
		int a ;
		char ch ;
		cin >> a >> ch ;
		while (a --){
			sum.push_back(ch) ;
		}
	}
	int len = sum.size() / 2 ;
	int cnt = 0 ;
	for (int i = 0 ; i < len ; ++ i){
		if (sum[0] != sum[sum.size() - i - 1])
			++ cnt ;
	}
	cout << cnt ;
	return 0 ;
}

























