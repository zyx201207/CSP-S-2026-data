#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[501],b[500001];
long long f[505][505],s[505][505],h[505][505];
long long ans = 0;
int f1 = 1;
int d1 = INT_MIN;
void dfs(int x,int y){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= d1;j++){
			if(s[i][a[j]] == y || f1 == 0){
				f1 = 0;
				cout << ans << endl;
				return;
			}
			if(s[i][j] == 0){
				return;
				s[i][j] = 0;
			}
			else return; 
			ans += h[i][j];
		}
		ans += a[i];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> b[i];
	}
	for(int j = 1;j <= n;j++){
		int w;
		cin >> w;
		d = max(w,d);
		for(int i = 1;i <= w * 2;i++){
			cin >> a[i];
		}
		for(int i = 1;i <= w * 2;i += 2){
			f[j][a[i]] = a[i - 2];
			s[j][a[i - 2]] = a[i];
		}
		for(int i = 1;i <= w * 2;i += 2){
			h[j][a[i]] = a[i + 1];
		}
	}
	int x,y;
	for(int i = 1;i <= q;i++){cin >> x >> y;dfs(x,y);}
	return 0;
}