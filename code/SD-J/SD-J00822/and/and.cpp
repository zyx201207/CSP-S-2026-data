#include <bits/stdc++.h>
using namespace std;

int n , m , a[3005] , maxn = 0 , mxans = 0;

int main (){
	freopen ("and.in" , "r" , stdin);
	freopen (" and.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		if (a[i] > maxn){
			maxn = a[i];
		}
	}
	if (m == 1){
		cout << maxn;
		return 0;
	}//²âÊÔµã6 
	if (m == 2){
		for (int i = 1 ; i <= n ; i ++){
			for (int j = 1 ; j <= n ; j ++){
				if (i != j){
					mxans = max (mxans , (a[i] & a[j]));
				}
			}
		}
		cout << mxans;
		return 0;
	}//²âÊÔµã8~10 
//	if (m == 3){
//		for (int q = 1 ; q <= n ; q ++)
//			for (int i = 1 ; i <= n ; i ++){
//				for (int j = 1 ; j <= n ; j ++){
//					if ((q != j) && (q != i)){
//						mxans = max (mxans , ((a[q] & a[i])&a[j]));
//					}
//				}
//			}
//		cout << mxans;
//		return 0;
//	}
	return 0;
}

