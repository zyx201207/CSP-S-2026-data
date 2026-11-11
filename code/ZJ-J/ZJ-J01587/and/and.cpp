#include <bits/stdc++.h>
using namespace std;

long long a[200010];
int dp[200010];
int n,m;

void dfs(int x,int y){
	if(y == 1) cout << dp[n];
	string s;
	int cnt = 0;
	while(x != 0){
		s[++cnt] = x%2;
		x /= 2;
	}
	for(int i = x + 1; i <= n; i++){
		string c,d;
		int cnt1 = 0;
		while(a[i] != 0){
			c[++cnt1] = x%2;
			x /= 2;
		}if(s > c){
			for(int j = 0; j < s.size(); j++){
				if(s[j] == c[j] && s[j] == '1'){
					d[j] = '1';
				}else{
					d[j] = '0';
				}
			}
		}else{
			for(int j = 0; j < c.size(); j++){
				if(s[j] == c[j] && s[j] == '1'){
					d[j] = '1';
				}else{
					d[j] = '0';
				}
			}
		}
		int y;
		for(int k = d.size(); k > 0; k--){
			int cnt = 1;
			y += (d[k] - '0')*cnt;
			cnt *= 2;
		}
		dp[i] = max(dp[i - 1],y);
	}
	y--;
	dfs(dp[n],y);
}


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1,m);
	
	return 0;
}
