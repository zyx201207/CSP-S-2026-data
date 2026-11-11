#include<bits/stdc++.h>
using namespace std;
long long a[500001], pre[500001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	int maxn = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int flag = 0;
	long long t = a[2]-a[1];
	for(int i = 2; i <= n; i++){
		if(a[i]-a[i-1] != t){
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		long long maxn = 0;
		for(long long i = 0; i <= n; i++){
			if(t*i*(i-1ll) <= 2ll*m){
				maxn = max(maxn, i);
			}else{
				break;
			}
		}
		cout << maxn;
	}else if(n <= 30000){
		for(int i = 1; i <= n; i++){
			pre[i] = pre[i-1]+a[i];
		}
		for(int i = 1; i <= n; i++){
			for(int j = i-1; j >= 1; j--){
				if((i-j)*a[i]-(pre[i-1]-pre[j-1]) > m){
					maxn = max(maxn, i-j);
					break;
				}
			}
			if((i-1)*a[i]-(pre[i-1]-pre[0]) <= m) maxn = max(maxn, i);
		}
		cout << maxn;
	}
	return 0;
}
