#include<bits/stdc++.h>
using namespace std;

long long a[2000005];

bool zd(int b,int c,int e) {
	if(a[b] - a[c] == 1) {
		return false;
	}
	if(a[b] - a[c] < e) {
		return false;
	}
	if((b - c) % e == 0) {
		return false;
	}
	if(e - (b - c) % e == 1) {
		return true;
	}
	return false;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c >> t;
	
	while(t --) {
		int m,ans = 0,s = 0;
		long long d;
		cin>>m >>d;
		for(int i = 1; i <=m; i ++) {
			cin >> a[i];
		}
		for(int i = m; i >= 1; i --) {
			if(a[i] - a[i - 1] > d) {
				a[i] = 0;
				s ++;
			}
		}
		m -= s;
		for(int i = 1; i <= m; i ++) {
			a[i] = abs(a[i]);
		}
		sort(a + 1,a+ m + 1);
		for(int i = 1; i <= m; i ++) {
			for(int j = i; j <= m; j ++) {
				if(zd(j,i,d)) {
					ans ++;
				}
			}
		}
		cout <<ans <<"\n";
	}
	
	return 0;
} 
