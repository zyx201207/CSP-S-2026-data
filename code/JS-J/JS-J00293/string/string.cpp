#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int a[200005];
char c[200005];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int idx=0;
	for (int i=1;i<=n;i++) {
		int ta;
		char tc;
		cin >> ta >> tc;
		if (c[idx] == tc) {
			a[idx] += ta;
		} else {
			a[++idx] = ta;
			c[idx] = tc;
		}
	}
	if (idx==1) {
		cout << 0;
		return 0;
	}
	int cnt=0;
	int l=0,r=0;
	int i=1,j=idx;
	for (;i<=j;++i,--j) {
		l += a[i];
		r += a[j];
		/*if (c[i] != c[j]) {
			if (a[i] >= a[j]) {
				int x = a[i]-a[j];
				cnt += a[i];
				c[i] = c[j];
				a[i] = a[j];
				a[i+1] += x;
			} else {
				int x = a[j]-a[i];
				cnt += a[j];
				c[j] = c[i];
				a[j] = a[i];
				a[j-1] += x;
			}
		}*/
	}
	--i,++j;
	r -= a[j];
	int middle_idx=i;
	if (l!=r) {
		if (l<r) {
			while (l<r) {
				middle_idx++;
				r -= a[middle_idx];
				l += a[middle_idx];
			}
			if (l > r) {
				middle_idx--;
				}
		} else {
			while (l>r) {
				l -= a[middle_idx];
				r += a[middle_idx];
				middle_idx--;
			}
			if (l < r) {
				middle_idx++;
				}
		}
	}
	for (int x=1,y=idx;x<=middle_idx&&y>=middle_idx;x++,y--) {
		if (c[x]!=c[y]) {
			if (a[x]>=a[y]) {
				cnt += a[x];
				int tmpx = a[x]-a[y];
				a[x+1] += tmpx;
				a[x] = a[y];
				c[x] = c[y];
			} else { // a[x] < a[y]
				cnt += a[y];
				int tmpx = a[y]-a[x];
				a[y-1] += tmpx;
				a[y] = a[x];
				c[y] = c[x];
				}
		}
	}
	cout << cnt;
	return 0;
}

/*
 * 6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
 * */
