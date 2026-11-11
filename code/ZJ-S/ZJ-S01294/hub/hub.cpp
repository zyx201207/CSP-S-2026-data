#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
long long n, m, l, ma;
long long p[N], d[N];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	l = 0;
	ma = 0;
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) cin >> p[i];
	
	sort(p, p+n);
	
	for(int i = 1; i < n-1; i++){
		d[i] = p[i] - p[i-1];
	}
	
	long long t = 1;
	long long sum = 0;
	
	for (int i = 1; i < n-1; i++){
		ma += d[i]*t;
		t++;
		if (ma > m) {
			ma = ma-(p[i]-p[l]);
			l++;
			t--;
		}
		sum = max(sum, t);
	}
	
	cout << sum << endl;
	
	return 0;
}
