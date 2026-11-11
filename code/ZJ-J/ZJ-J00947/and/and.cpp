#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, m, ans;
long long a[N], vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++) cin >> a[i];
	
	for(long long i = 30; i >= 0; i--){
		long long cnt = 0;
		for(long long j = 1; j <= n; j++){
			if(vis[j]) continue;
			if((a[j] >> i) & 1) cnt ++;
		}
		if(cnt >= m){
			ans += (1 << i);
			for(long long j = 1; j <= n; j++){
				if(vis[j]) continue;
				if(!((a[j] >> i) & 1)) vis[j] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}