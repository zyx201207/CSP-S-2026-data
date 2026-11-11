#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N], c[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	for(int i = 1; i < n; i++) c[i] = a[i+1]-a[i];
	bool dc = true;
	for(int i = 1; i < n-1; i++){
		if(c[i] != c[i+1]){
			dc = false;
			break;
		}
	}
	if(dc){
		cout << m/c[1]+1 << '\n';
		return 0;
	}
	int len = 0;
	long long sum = 0;
	int l = 1, r = 0;
	while(r < n){
		if(sum > m){
			sum = sum+a[l]-a[r+1]+c[r+1]*len;
			l++, r++;
			if(r == n) break;
			continue;
		}
		while(true){
			if(sum+c[r+1]*(len+1) <= m){
				sum += c[r+1]*(len+1);
				r++, len++;
			}
			else{
				sum = sum+a[l]-a[r+1]+c[r+1]*len;
				l++, r++;
				break;
			}
		}
		if(r == n) break;
	}
	cout << len+1 << '\n';
	return 0;
}
