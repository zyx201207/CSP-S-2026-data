#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005
#define FZERO 100000

int n, m;
int a[MAXN], poss[MAXN];
int anss;

signed bigg(int a1, int a2){
	int d = a2 - a1;
	int ans;
	int mm = 0;
	for(int i = 0; i < n; ++i){
		mm += i*d;
		if (m > mm) ++ans;
		else {
			cout << ans-1;
			return 0;
		}
	}
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	int maxax = 0;
	int a1, a2;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if(i==1) a1 = x;
		if(i==2) a2 = x;
		
		int y = x;
		if (y>0) y = -y;
		y += FZERO;
		if (y<0) return bigg(a1, a2);
		
		x += FZERO;
		a[x] += 1;
		if(x > maxax) maxax = x;
	}
	
	int p = 1;
	for(int i = 1; i <= n; ++i) {
		if (a[i]) {
			bool flag = false;
			for(int j = 1; j <= i; ++j){
				if(j < i-m) j = i-m;
				if(a[j]){
					flag = true;
					break;
				}
			}
			if(flag){
				poss[p++] = i;
			}
		}
	}
	
	for(int i = 1; i < MAXN; ++i){
		if(!a[i]) continue;
		int mm = m;
		int p = i;
		//cout << "i=" << i-FZERO << ":\n";
		int ans = a[p];
		//cout << ans << "\n";
		while(mm>0 && p>0){
			--p;
			if(!a[p]) continue;
			if(a[p] <= mm/(i-p)) {
				ans += a[p];
				mm -= a[p]*(i-p);
				//cout << "  " << p-FZERO << " ap" << a[p] << " mm" << mm  << " ans" << ans << "\n";
				continue;
			}
			if(a[p] > mm/(i-p)) {
				ans += mm/(i-p);
				//cout << " -" << p-FZERO;
				break;
			}
		}
		//cout << ans << "\n\n" << endl;
		if (ans > anss) anss = ans;
	}
	
	cout << anss << endl;
	
	return 0;
}
