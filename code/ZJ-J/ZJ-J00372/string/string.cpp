#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+10;

int n,ans;
int a[N];
char c[N];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i] >> c[i];
	}
	int l = 1,r = n,x = 1,y = 1;
	while (l < r){
		int px = a[l]-x+1,py = a[r]-y+1;
		if (px == py){
			if (c[l] != c[r])ans += px;
			x = 1,y = 1;
			l++,r--;
		}
		else{
			if (px < py){
				if (c[l] != c[r])ans += px;
				x = 1;
				l++;
				y += px;
			}
			else{
				if (c[l] != c[r])ans += py;
				y = 1;
				r--;
				x += py;
			}
		}
	}
	cout << ans;
	return 0;
}
