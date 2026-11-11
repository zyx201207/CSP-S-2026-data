#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m, a[N], s[N], x, y, ans;

int M_fi(int l, int r, int i){
	//cout << i << ' ';
	if(l >= r){
		while(a[i] * (i-l) + s[l-1]-s[i-1] >= m){
			l --;
			if(l < 1) break;
		}
		//cout << ' ' << l << ' ';
		if(a[i] * (i-l) + s[l-1]-s[i-1] > m) return l + 1;
		return l;
	}
	int mid = l + r >> 1;
	//cout << mid << '\n';
	if(a[i] * (i-mid) + s[mid-1]-s[i-1] > m) return M_fi(mid+1, r, i);
	else if(a[i] * (i-mid) + s[mid-1]-s[i-1] <= m) return M_fi(l, mid, i);
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld", &n, &m);
	for(int i = 1; i <= n; i ++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	long long u = 0 - a[1] + 1;
	for(int i = 1; i <= n; i ++){
		a[i] += u;
		s[i] = s[i-1] + a[i];
	}
	//×¢Òâa[1] 
	for(int i = 1; i <= n; i ++){
		y = M_fi(1, i, i);
		while(a[i] == a[i+1]){
			i ++;
		}
		ans = max(ans, i - y + 1);
		//cout << ans << ' ' << '\n';
	}
	printf("%lld", ans);
	return 0;
}

