#include <bits/stdc++.h>
#define ll long long
const int MAXN = 2e6 + 5;
using namespace std;
long long read(){long long r = 0,f = 1;char c = getchar();while(c == '-' || (c >= '0' && c <= '9')){if(c == '-'){f = -1;}else{r *= 10;r += int(c - '0');}c = getchar();}while(c >= '0' && c <= '9'){r *= 10;r += int(c - '0');c = getchar();}return r * f;}
ll c,t,n,d,ans = 0;
ll land[MAXN];
ll best[MAXN],ct[MAXN];
void dfs(int now,int num){
//	cout << best[now] << " " << num << endl;
	if(num < best[now]){
//		cout << now << " " << num << endl;
//		if(now == 4) cout << num << " " << best[now] << " " << ct[now] << endl;
		ct[now] = 1;
		best[now] = num;
	}else if(num == best[now]) ct[now] ++;
	int cur = now + 1;
	while((land[cur] - land[now]) <= d && cur <= n){
//		cout << cur << " " << now << " " << land[cur] - land[now] << endl;
		dfs(cur,num + 1);
		cur ++;
//		cout << cur;
//		if(cur == 3 && now == 1) cout << land[cur] - land[now] << " " << " ljhsdfkjdfkjg" << endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(),t = read();
while(t --){
	ans = 0;
	memset(best,0x3f3f3f,sizeof(best));
	memset(ct,0,sizeof(ct));
	n = read();
	d = read();
	for(int i = 1;i <= n;i ++){
		land[i] = read();
	}
//	for(int i = 1;i <= n;i ++){
//		cout << land[i] << " ";
//	}
	for(int i = 1;i <= n;i ++){
		memset(best,0x3f3f3f,sizeof(best));
		memset(ct,0,sizeof(ct));
		dfs(i,0);
		for(int j = i + 1;j <= n;j ++){
			if(ct[j] == 2) ans ++;
//			cout << ct[j] << " ";
		}
//		cout << endl;
	}
	cout << ans << endl;
}
	return 0;
}
