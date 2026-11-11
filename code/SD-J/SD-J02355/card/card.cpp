#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 5;
LL a[N], f[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	LL n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	if(m == 1) cout << n;
	else if(m == 2){
		LL ans = 0;
		f[a[n]] = n;
		for(int i = n - 1;i >= 1;i --){
			if(a[i] != a[n]){
				for(int j = i;j >= 1 && a[j] != a[n];j --) ans ++;
				break;
			}
			
		}
		if(a[n] == 1) f[2] = ans;
		if(a[n] == 2) f[1] = ans;
		cout << f[1] << ' ' <<  f[2];		
	}
	else{
		for(int i = 1;i <= n;i ++){
			f[a[i]] = i;
		} 
		for(int i = 1;i <= m;i ++) cout << f[i] << ' ';
	}
	return 0;
}
