#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], max_n;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	//n = 100005;
	//cout << n;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	//sort(a+1, a+n+1);
	//max_n = a[1];
	for(int i = 1;i<n;i++){
		for(int j = i+1;j<=n;j++){
			if(a[i]&a[j]>max_n) max_n = a[i]&a[j];
		}
	}
	cout << max_n;
	return 0;
}
