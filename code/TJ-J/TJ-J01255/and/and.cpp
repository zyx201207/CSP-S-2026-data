#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, u, maxn = 0;
	vector <long long> a;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		long long x;
		cin >> x;
		a.push_back(x);
	}
	if (m == 1){
		for(int i = 0;i <= n - 1;i++){
			if(a[i] > maxn){
				maxn = a[i];
			}
		}
	}
	else if (m == n){
		for (int i = 1;i < n;i++){
			u = a[i] & a[i - 1];
		}
		cout << u;
		return 0;
	}
	else{
		for(int i = 0;i <= n - 1;i++){
			for(int j = 0;j <= n - 1;j++){
				if (a[i] == a[j])
				{
					continue;
				}
				int y = a[i] & a[j];
				if (y > maxn){
					maxn = y;
				}
			}
		}
	}
	
	cout << maxn;
	return 0;
}

