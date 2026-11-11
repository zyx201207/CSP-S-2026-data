#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, a[2000005], nxt[2000005], nxtt[2000005], da;
void solve(){
	da = 0;
	scanf("%lld %lld", &n, &d);
	for(int i = 1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 1;i<=n;i++){
		nxt[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
		nxtt[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
//		printf("%lld %lld\n", nxt[i], nxtt[i]);
	}
	vector<long long> a, b;
	for(int i = 1;i<=n;i++){
		for(int j = nxt[i] + 1;j<=n;j++){
			a.clear();
			b.clear();
			long long now = i, cantarrive = 0;
			while(nxt[now]<j){
				if(now==nxt[now]){
					cantarrive = 1;
					break;
				}
				now = nxt[now];
				a.push_back(now);
			}
			if(cantarrive){
				break;
			}
			now = j;
			while(nxtt[now]>i){
				now = nxtt[now];
				b.push_back(now);
			}
			reverse(b.begin(), b.end());
			if(a.size()==b.size()){
				long long sam = 1, m = a.size(), cnt = 0;
				for(int j = 0;j<=m - 1;j++){
					if(a[j]!=b[j]){
						sam = 0;
						if(abs(a[j] - b[j])>1){
							cnt = 2;
							break;
						}else{
							cnt++;
						}
					}
				}
				if(!sam&&cnt==1){
					da++;
//					printf("   %lld %lld\n", i, j);
//					for(auto i : a){
//						printf("%lld ", i);
//					}
//					printf("\n");
//					for(auto i : b){
//						printf("%lld ", i);
//					}
//					printf("\nend\n");
				}
			}
		}
	}
	printf("%lld\n", da);
}
void solve2(){
	da = 0;
	scanf("%lld %lld", &n, &d);
	for(int i = 1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	for(int i = 1;i<=n;i++){
		for(int j = nxt[i];j!=nxt[j];j = nxt[j]){
			da++;
		}
	}
	printf("%lld\n", da);
}
void solve3(){
	da = 0;
	scanf("%lld %lld", &n, &d);
	for(int i = 1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	long long D = a[2] - a[1], cnt = d / D;
	if(cnt==0||cnt==1){
		printf("0\n");
	}else{
//		for(int i = cnt + 1;i<=n;i += cnt + 1){
//			da += n - i + 1;
//			printf("%lld %lld\n", i, da);
//		}
		printf("%lld\n", max(0LL, n - cnt - 1));
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld %lld", &c, &t);
	if(c<=6){
		while(t--){
			solve();
		}
	}else if(c<=10){
		while(t--){
			solve2();
		}
	}else if(c<=12){
		while(t--){
			solve3();
		}
	}else{
		while(t--){
			solve2();
		}
	}
	return 0;
}
