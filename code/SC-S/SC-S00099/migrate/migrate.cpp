#include<bits/stdc++.h>
using namespace std;
int x[2000010];
int n, d;
long long len, cnt;
int b[2000010];
void dfs(int s, int e, int cd){
	b[s] = 1;
	if(s == e){
		if(cd < len) len = cd,cnt = 1;
		else if(cd == len) cnt++;
		return ;
	}
	for(int i = s + 1; i <= n; i++){
		if(!b[x[i]]){
			b[x[i]] = 1;
			dfs(x[i],e,cd+1);
			b[x[i]] = 0;
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	cin >> c >> t;
	for(int i = 1; i <= t; i++){
		cin >> n >> d;
		int ans = 0;
		memset(x,0,sizeof(0));
		for(int j = 1; j <= n; j++){
			cin >> x[i];
		}
		for(int j = 1; j <= n; j++){
			for(int k = j + 1; k <= n; k++){
				len = 2e18, cnt = 0;
				//memset(b,0,sizeof(b));
			    dfs(j,k,0);
			    //cout <<j << ' ' << k << ' ' << cnt << ' '<< len << endl;
			    if(cnt == 2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}