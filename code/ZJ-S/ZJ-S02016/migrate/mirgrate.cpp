#include <bits/stdc++.h>
using namespace std;
inline void read(long long &x){
	long long k = 0,c = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-'){
			c = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		k *= 10;
		k += ch - '0';
		ch = getchar();
	}
	x = k * c;
}
long long n,m,ans,t;
long long nxt[2000100],pre[2000100];
long long a[2000100];
long long mi[2000100],dp[2000100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(t);
	read(t);
	while(t--){
		ans = 0;
		read(n);
		read(m);
		int l = 1,r = 0; 
		for(int i = 1;i <= n;i++){
			read(a[i]);
		}
		for(int i = 1;i <= n;i++){
			while(r < n && a[r + 1] - a[i] <= m){
				r++;
			}
			nxt[i] = r;
			while(l < i && a[i] - a[l] > m){
				l++;
			}
			pre[i] = l;
		}
		for(int i = 1;i <= n;i++){
			memset(mi,0x3f,sizeof(mi));
			memset(dp,0,sizeof(dp));
			dp[i] = 1;
			mi[i] = 0;
			for(int j = i + 1;j <= n;j++){
				for(int k = max(int(pre[j]),i);k <= j;k++){
					if(mi[k] + 1 < mi[j]){
						mi[j] = mi[k] + 1;
						dp[j] += dp[k];
					}else if(mi[k] + 1 == mi[j]){
						dp[j] += dp[k];
					}
				}
				if(dp[j] == 2){
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
