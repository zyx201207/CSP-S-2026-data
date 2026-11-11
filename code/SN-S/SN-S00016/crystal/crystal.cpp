#include<bits/stdc++.h>
using namespace std;

long long a[500005], cf[500005];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	long long maxn = INT_MIN;
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for(int i = 1; i < n; i ++){
		long long sum = 1;
		
		for(int j = i + 1; j <= n; j ++){
			cf[j - i] = a[j] - a[j - 1];
		}
		
		int j = 1;
		while(m - j * cf[j] >= 0){
			sum += 1;
			m -= j * cf[j];
			j ++;
		}
		
		maxn = max(sum, maxn);
	}
	
	cout << maxn;
	
	return 0;
}
