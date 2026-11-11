#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","a",stdin);
	freopen("and.out","b",stdout);
	int n,m;
	cin >> n,m;
	int a[n],ans = 0;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		if(a[i] & m >= ans){
			ans = a[i] & m;
		}
	}
	cout << ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
