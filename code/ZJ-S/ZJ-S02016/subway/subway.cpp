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
long long dp[1010][1010];//从地i个地铁站站台到第j个所需时间 
long long n,m,q,d,k,k1;
long long s,t;
long long sub[1010],ti[1010];
long long jz[1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	read(n);
	read(n);
	read(m);
	read(d);
	read(q);
	for(int i = 1;i <= m;i++){
		read(jz[i]);
	}
	for(int i = 1;i <= n;i++){
		read(k);
		for(int j = 1;j <= k;j++){
			read(sub[j]);
			read(ti[j]);
		}
		for(int j = 1;j <= k;j++){
			for(int l = 1;l <= k;l++){
				if(j == l){
					continue;
				}
				dp[sub[j]][sub[l]] = min(dp[sub[j]][sub[l]],ti[j] + ti[l]);
			}
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++){
			if(j == i){
				continue;
			}
			for(int l = 1;l <= m;l++){
				if(j == l || l == i){
					continue;
				}
				dp[j][l] = min(dp[j][l],dp[j][i] + dp[i][l]);
			}
		}
	}
	for(int i = 1;i <= q;i++){
		read(s);
		read(t);
		cout << jz[s] + jz[t] + dp[s][t] << "\n";
	}
	return 0;
}
