#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	clock_t st = clock();
	freopen("crystal.in", "r",stdin);
	freopen("crystal.out", "w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	int s[n];
	bool fl = true;
	for(int i = 0;i<n;i++){
		cin >> s[i];
	}
	sort(s,s+n);
	int cnt = s[1] - s[0];
	for(int i = 2;i<n;i++){
		if(s[i] - s[i-1] != cnt) fl = false;
	}
	if(fl == true){
		cnt = m / cnt;
		for(int i = 1;i<n;i++){
			cnt = cnt-i;
			if(cnt <= 0){
				cout << i;
				return 0;
			}
		}
	}
	for(int i = n-1;i >= 0;i--){
		int sum = 0;
		for(int j = 0;j<i;j++){
			sum += s[i]-s[j];
		}
		if(sum <= m){
			cout << i+1;
			break;
		}
	}
	
	clock_t et = clock();
	double sec = double(et - st) / CLOCKS_PER_SEC;
	double ms = sec*1000;
	cerr << "耗时：" << ms << "ms";
	return 0;
}
