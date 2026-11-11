#include <bits/stdc++.h>

using namespace std;
long long n , m , a[200005] , max_ = 0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	fropen("and.in" , "r" , stdin);
	fropen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}
	if(m == 1){
		for(int i = 0;i < n;i ++){
			if(a[i] > max_){
				max_ = a[i];
			}
		}
		cout << max_;
		return 0;
	}
	for(int i = 0;i < n;i ++){
		for(int j = 0;j < i;j ++){
			if((a[i] & a[j]) > max_){
				max_ = (a[i] & a[j]);
			}
		}
	}
	cout << max_; 
	return 0;
} 
