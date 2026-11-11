#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 +5;
int n;
long long m, a[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long ans = 1;
	for(int i = 1; i + ans - 1 <= n; i ++){
		long long sum = 1;
		int j = i + 1, c = 1;
		long long k = m;
		while(j <= n){
			if(k - c * (a[j] - a[j - 1]) >= 0){
				k -= c * (a[j] - a[j - 1]);
				sum ++;
				c ++;
				j ++;
			}
			else break;
		}
		ans = max(ans, sum);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
