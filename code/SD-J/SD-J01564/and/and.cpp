#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n,m;
long long a[N],s[N],maxx = - 100000;
bool flag = true;

bool cmp(int x,int y) {
	return x > y;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] != i - 1) flag = false;
	}
	if(m == 1) {
		sort(a + 1,a + 1 + n,cmp);
		cout << a[1];
		return 0;
	}
	if(flag == true) {
		sort(a + 1, a + 1 + n,cmp);
		s[1] = a[1];
		for(int i = 2; i <= m; i++) {
			s[i] = s[i - 1]&a[i];
		}
		cout << s[m];
	}
	if(m == 2) {
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				maxx = max(maxx,a[i]&a[j]);
			}
		}
		cout << maxx;
		return 0;
	}
	else {
		sort(a + 1,a + 1 + n,cmp);
		cout << a[m];
		return 0;
	}
	cout << "0";
	return 0;
}
