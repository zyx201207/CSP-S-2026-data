#include<bits/stdc++.h>
using namespace std;

long long a[200005];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	long long m, n, sum = (1 << 30) - 1;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for(int i = n; i >= n - m + 1; i --){
		sum = (sum & a[i]);
	}
	
	cout << sum;
	
	return 0;
}
