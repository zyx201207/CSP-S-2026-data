#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 * 2 + 100;
int o[N];
char p[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long t = 0;
	string a;
	for (int i = 1; i <= n; i++) {
		int x;
		char y;
		cin >> x >> y;
		for (int j = 1; j <= x; j++) {
			a += y;
		}
	}
	int b = a.length();
	long long cnt = 0;
	for (int i = 0; i < b / 2; i++) {
		if (a[i] != a[b - i - 1]) {
			cnt++;
		}
	}
	cout << cnt;
	/*
	long long sum=0;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		sum+=x;
		o[i]=x;
		p[i]=y;
	}
	for(int i=1;i<=n;i++){
		if(i!=n&&a[i+1]<sum/2){
			
		}
	}
	*/
	return 0;
}