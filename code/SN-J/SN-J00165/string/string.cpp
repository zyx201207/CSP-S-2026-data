#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
long long ans, cnt, k1, k2, m;
int n;
struct e{
	long long l;
	char z;
};
e c1[maxn], c2[maxn];
e a[maxn];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> a[i].l >> a[i].z;
		cnt += a[i].l;
	}
	cnt /= 2;
	long long sum = 0;
	for (int i = 1; i <= n; i ++){
		k1 ++;
		if (sum + a[i].l >= cnt){
			c1[i].l = cnt - sum; 
			c1[i].z = a[i].z;
			break;
		}else{
			sum += a[i].l;
			c1[i].l = a[i].l; 
			c1[i].z = a[i].z;
		}
	}
	sum = 0;
	for (int i = n; i >= 1; i --){
		k2 ++;
		if (sum + a[i].l >= cnt){
			c2[k2].l = cnt - sum; 
			c2[k2].z = a[i].z;
			break;
		}else{
			sum += a[i].l;
			c2[k2].l = a[i].l; 
			c2[k2].z = a[i].z;
		}
	}
	for (int i = 1, j = 1; i <= k1 || j <= k2; ){
		if (c1[i].z != c2[j].z){
			if (m >= 0){
				ans += min(m, c2[j].l);
				m -= c2[j].l;
				j ++;
			}else{
				ans += min(-m, c1[i].l);
				m += c1[i].l;
				i ++;
			}
		}else{
			if (m >= 0){
				m -= c2[j].l;
				j ++;
			}else{
				m += c1[i].l;
				i ++;
			}
		}
	}
	cout << ans;
	return 0;
} 
