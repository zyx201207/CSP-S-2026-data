#include<bits/stdc++.h>
using namespace std;
struct one(int x,int y) {
	for (int i = 1;i <= x;i ++){
		if (max(x,y) >= nfirst || max(x,y) >= nsecond){
			return x > y;
		}
	}
};
bool check(int flag){
	flag = true;
}
struct island(int a,b){
	while (a > b){
		for (int i = a;i >= 2;i --){
			a = s[i] + max(f[i] - 1,f[d] - s[f[i] - 1]);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int s[i],st[i],f[];
	int c,t;
	cin >> c >> t;
	int none,done;
	cin >> none >> done;
	for (int i = 1;i <= none;i ++){
		cin >> s[i];
	}
	int nt,dt;
	cin >> nt >> dt;
	for (int i = 1;i <= nt;i ++){
		cin >> st[i];
	}
	for (int i = 1;i <= dt;i ++){
		for (int j = 1;j <= nt;j ++){
			check();
			if (s[i] >= st[j]){
				flag = false;
			}
			else {
				flag = true;
			}
			while (flag){
				f[i][j] = max(s[i] + d[i],max(st[j+d] + st[j-1],dt[i][j] - dp[i-1][j-dt[i]]));
				continue;
			}
		}
	}
	one();
	island();
	return 0;
}

