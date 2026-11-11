//6/20 + 1/20 + ???
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll m;
ll a[500010];
ll b[500010];

int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);/*
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);*/
	cin >> n >> m;
	bool bA = 1,bB = 1;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		if (i >= 3 && abs (a[i] - a[i - 1]) != abs (a[i - 1] - a[i - 2])) {
			bB = 0;
		}
		if (a[i] != i) {
			bA = 0;
		}
	}
	
	if (bA) {//特A(1,2,3...)
		int y = 0,t = 1;
		for (int i = 1;;i++) {
			if (y > m) {
				cout << t << "\n";
				return 0;
			}
			y += i;
			t++;
		}
	} else if (bB) {//特B(等差)
		int cha = abs (a[2] - a[1]);
		int y = 0,t = 1;
		for (int i = 1;;i += cha) {
			if (y > m) {
				cout << t << "\n";
				return 0;
			}
			y += i;
			t++;
		}
	}
	
	//不变 
	sort (a + 1,a + n + 1);
	ll ans = 1,t = 0;
	bool bb = 0;
	for (int i = 2;i <= n;i++) {
		if (bb) {
			if (a[i] == a[i - 1]) {
				t++;
			} else {
				ans = max (ans,t);
				t = 0;
				bb = 0;
			}
		} else {
			if (a[i] == a[i - 1]) {
				bb = 1;
				t = 2;
			}
		}
	}
	ans = max (ans,t);
	
	//降序差分 
	sort (a + 1,a + n + 1);
	memset (b,0,sizeof (b));
	b[n] = 0;
	for (int i = n;i >= 1;i--) {
		b[i] = a[i + 1] - a[i];
	}
	int p = n,y = 0;
	t = 1;
	for (;;) {
		if (p < 1) {
			break;
		}
		if (y > m) {
			t--;
			break;
		}
		p--;
		int cha = b[p];
		for (int i = n;i > p;i--) {
			y += cha;
		}
		t++;
	}
	ans = max (ans,t);
	
	//升序差分 
	sort (a + 1,a + n + 1);
	b[1] = 0;
	for (int i = 2;i <= n;i++) {
		b[i] = a[i] - a[i - 1];
	}
	p = 1,y = 0;
	t = 1;
	for (;;) {
		if (p > n) {
			break;
		}
		if (y > m) {
			t--;
			break;
		}
		p++;
		int cha = b[p];
		for (int i = 1;i < p;i++) {
			y += cha;
		}
		t++;
	}
	ans = max (ans,t);

	//最小差分
	t = 1;
	int minn = 1;
	for (int i = 1;i <= n;i++) {
		if (b[i] < b[minn]) {
			minn = i;
		}
	}
	//-正 
	p = minn,y = 0;
	t = 1;
	for (;;) {
		if (p > n) {
			break;
		}
		if (y > m) {
			t--;
			break;
		}
		p++;
		int cha = b[p];
		for (int i = minn;i < p;i++) {
			y += cha;
		}
		t++;
	}
	ans = max (ans,t);
	//-反
	p = minn,y = 0;
	t = 1;
	for (;;) {
		if (p < 1) {
			break;
		}
		if (y > m) {
			t--;
			break;
		}
		p--;
		int cha = b[p];
		for (int i = minn;i > p;i--) {
			y += cha;
		}
		t++;
	}
	ans = max (ans,t);
	cout << ans << "\n";
	return 0;
}
