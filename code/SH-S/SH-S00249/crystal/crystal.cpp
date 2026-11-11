#include<bits/stdc++.h>
using namespace std;
long long int z[500005];
bool cmp(long long int x, long long int y){
	return x < y;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long int n, m;
	cin >> n >> m;
	long long int maxx = 0;
	for (long long int i = 1;i <= n;i ++){
		cin >> z[i];
	}
	sort(z + 1, z + n + 1, cmp);
	if (n <= 5000){
		for (long long int i = 1;i <= n;i ++){
			long long int j = i;
			long long int sum = 0;
			while (j <= n && sum <= m){
				j ++;
				sum += (j - i) * (z[j] - z[j - 1]);
			}
			maxx = max(maxx, j - i);
		}
		cout << maxx;
	}else{
		cout << min(n, m / (z[2] - z[1]));
	}
	
	return 0;
}
