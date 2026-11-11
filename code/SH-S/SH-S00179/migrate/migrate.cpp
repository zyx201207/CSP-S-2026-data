#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int far[2000005],pre[2000005];
long long cnt[5005][5005];
int check(int u,int v){
	if(cnt[u][v]) return cnt[u][v];
	if(far[u] == u || pre[v] == v || u > v){
		cnt[u][v] = 0;
		return 0;
	}
	if(far[u] >= v){
		cnt[u][v] = 1;
		return 1;
	}
	if(pre[v] <= far[u]){
		if(far[u] - pre[v] == 0){
			cnt[u][v] = 1;
			return 1;
		}
		if(far[u] - pre[v] == 1){
			cnt[u][v] = 2;
			return 2;
		}
		cnt[u][v] = 3;
		return 3;
	}
	cnt[u][v] = check(u,far[far[u]]) * check(far[u],v);
	return cnt[u][v];
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n;
		long long d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		a[0] = -1e18 - 10;
		a[n + 1] = 1e18 + 10;
		for(int i = 1;i <= n;i++){
			for(int j = i;j >= 1;j--){
				if(a[i] - a[j - 1] > d){
					pre[i] = j;
					break;
				}
			}
			for(int j = i;j <= n;j++){
				if(a[j + 1] - a[i] > d){
					far[i] = j;
					break;
				}
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(check(i,j) == 2){
					ans++;
				}
			}
		}
		cout << ans << endl;
		memset(cnt,0,sizeof cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
