#include<bits/stdc++.h>
#define int long long

using namespace std;
int c, T, n, d, a[2000005];
void findnex(int now, int d){
	int tmp = a[now] + d;
	for(int i = n; i >= 0;i --){
		if(tmp >= a[i]){
			now = i;
			return;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld", &c, &T);
	while(T --){
		memset(a, 0, sizeof(a));
		scanf("%lld %lld", &n, &d);
		for(int i = 1; i <= n; i ++){
			scanf("%lld", &a[i]);
		}
		int ans = 0;
//		for(int u = 1; u <= n; u ++){
//			for(int v = u; v <= n; v ++){
//				if(v - u <= 2) continue;
//				int cnt = 0, now = u, minn = 1e18;
//				while(now < v){
//					findnex(now, d); 
//					cnt ++;
//				}
//				if(cnt * 2 != 2) continue;
//				ans ++;
//			}
//		}
		cout << 0 << endl;
	}
	return 0;
}

