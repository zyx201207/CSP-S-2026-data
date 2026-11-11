#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5000;
int n, a[N], ma;
long long m, c[N], cha[N], ch[N], f[N][N]={0};
//vector<long long> f[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> a[1];
	cha[1] = 0;
	for(int i = 2; i <= n; i ++){
		cin >> a[i];
		c[i] = a[i]-a[i-1];
		//cha[i] = cha[i-1]+(i-1)*(a[i]-a[i-1]);
		//ch[i] = ch[i-1] +(a[i]-a[i-1]);
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i ++){
		if(ma > n-i+1) break;
		for(int j = i+1; j <= n; j ++){
			f[i][j] = f[i][j-1] + (j-i)*c[j];
			if(f[i][j] <= m){
				ma = max(ma, j-i+1);
			}
		}
	}
	cout << ma;
	return 0;
}