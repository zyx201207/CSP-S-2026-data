#include<bits/stdc++.h>

using namespace std;
#define int long long

int n,m,f[200005][30],now = 1,ans;
int a[200005],b[200005];
char c[200005],lst = '0';

signed main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n; ++ i) {
		cin >> m >> c[i];
		a[i] = now;
		now += m;
		b[i] = now - 1;
		f[i][c[i] - 'a'] += m;
		for(int j = 0;j <= 26; ++ j) {
			f[i][j] += f[i - 1][j];
		}
	}
	for(int i = 1;i <= n; ++ i) {
		if(a[i] > now / 2) break;
		if(a[i] <= now / 2 && b[i] >= now / 2) {
			int d,dy,p = 0;
			if((now - 1) % 2 == 0) {
				d = (now - 1) / 2 - a[i] + 1;
				dy = b[i] - (now - 1) / 2;
			} else {
				d = now / 2 - a[i];
				dy = b[i] - now / 2;
			}
			if(d <= dy) continue;
			else {
				for(int j = i - 1;j >= 0;j --) {
					if(b[j] < now - b[i]) break;
					if(a[j] < now - b[i]) {
						if(c[j] == c[i]) p += b[j] - a[j] + 1;
					} else {
						p += b[j] - now + b[i] + 1;
					}
				}
			}
			ans += d - dy - p;
			//cout << d << " " << dy << " " << p; 
			continue;
		}
		int L = 1,R = n,l = 0,r = 0;
		while(L < R) {
			int mid = (L + R) >> 1;
			if(b[mid] < now - a[i]) L = mid + 1;
			else R = mid;
		}
		l = L;
		L = 1,R = n;
		while(L < R) {
			int mid = (L + R) >> 1;
			if(b[mid] < now - b[i]) L = mid + 1;
			else R = mid;
		}
		r = R;
		if(r < l) swap(l,r);
		//cout << l << " " << r << "\n";
		int ha = f[r][c[i] - 'a'] - f[l - 1][c[i] - 'a'];
		int nd = 0;
		if(c[r] == c[i]) {
			nd += abs(now - a[i] - b[r]);
		}
		if(c[l] == c[i]) {
			nd += abs(now - b[i] - a[l]);
		}
		ans += b[i] - a[i] + 1 - ha + nd;
		//cout << ha << " " << nd << "\n";
	} 
	//for(int i = 1;i <= n; ++ i) cout << f[i][0] << " ";
	cout << ans;

	return 0;
}
/*
4
3 a
2 b
1 c
1 a
*/
