#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	long long maxx = -1;
	for (int i = 1; i <= n; i++){
		vector<long long> d;
		for (int j = 1; j <= n; j++){
			if (j == i){
				continue;
			}
			d.push_back(abs(a[j] - a[i]));
		}
		long long sum = 0;
		long long ans = 1;
		sort(d.begin(),d.end());
		for (int a1 : d){
			sum += a1;
			if (sum > m){
				break;
			}
			ans++;
		}
		maxx = max(ans,maxx);
	}
	cout << maxx;
	return 0;
} 
