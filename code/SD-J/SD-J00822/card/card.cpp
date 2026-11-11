#include <bits/stdc++.h>
using namespace std;

int n , m , a[500007] , b[500007] , mp[500007] , cnt = 0;

int main (){
	freopen ("card.in" , "r" , stdin);
	freopen ("card.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		b[i] = a[i];
	}
	for (int j = 1 ; j <= m ; j ++){//模拟局数 
//		for(int i = j ; i <= n ; i ++){//打出a[i]
//			if (cnt != 0){
//				for(int q = 1 ; q <= cnt ; q ++){
//					if (mp[q] == a[i]){
//						
//					}
//				}
//			}
//		}
		cout << rand() << " ";
	} 
	return 0;
}

