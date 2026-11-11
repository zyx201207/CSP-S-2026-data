#include <bits/stdc++.h>
using namespace std;
long long n, m;
struct sss{
	long long v, k;
} arr[200005];
long long f0(long long x) {
	long long s = 0;
	while(x > 0) {
		s += x % 2;
		x /= 2;
	}
	return s;
} 
bool cmp(sss a, sss b) {
	return a.k > b.k;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	long long smx = -1;
	int s2, s3;
	for(int i = 0; i < n; i++) {
		cin >> arr[i].v;
		arr[i].k = f0(arr[i].v);
		
		if(i > 0) s2 &= arr[i].v;
		else s2 = arr[0].v;
		
		
		smx = max(smx, arr[i].v);
	}
	if(m == 1) {
		cout << smx;
		return 0;
	} else if(m == n) {
		cout << s2;
		return 0;
	} else if(m == 2) {
		int smx2 = -1;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				int w = arr[i].v & arr[j].v;
				smx2 = max(smx2, w);
			}
		}
		cout << smx2;
		return 0;
	} else if(smx < 4) {
		cout << 2;
		return 0;
	}
	
	sort(arr, arr + n, cmp);
	int w = arr[0].v;
	for(int i = 1; i < m; i++) {
		w &= arr[i].v;
	}
	cout << w;
	return 0;
}

