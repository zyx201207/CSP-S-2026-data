#include <bits/stdc++.h>
#define ll long long
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
long long ds,gs;
int c,t,d,n;
int a[2000010];
void zd(int x,int y){	// ok
	ds = 1;
	long long lj = 0;
	for(int i = x + 1;i <= y;i ++){
		if(lj + a[i] - a[i - 1] > d){
			lj = 0;
			ds ++;
		}
		lj += a[i] - a[i - 1];

	}
//	cout << x << ' ' << y << ' ' << ds << endl;
}
void dfs(int z,int ed,int lj,int ds1){
//	cout << z << ' ' << ed << ' ' << lj << ' ' << ds1 << endl;
	if(ds1 > ds) return;
	else if(z == ed){
		gs ++;
		return;
	}
	if(lj + a[z] - a[z - 1] > d){
		dfs(z + 1,ed,a[z] - a[z - 1],ds1 + 1);
	}else{
		dfs(z + 1,ed,a[z] - a[z - 1],ds1 + 1);
		dfs(z + 1,ed,lj + a[z] - a[z - 1],ds1);
	}
}
bool check(int x,int y){
	zd(x,y);
//	cout << "段数"<< ds<<endl;
	if(ds == 1) return false;
	gs = 0;
	dfs(x + 1,y,a[x + 1] - a[x],1);
//	cout <<"个数"<< gs << endl;
//	cout << gs <<endl;
	if(gs == 2) return true;
	else return false;
}
int main(){
	FIO
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t --) {
		ll ans = 0;
		cin >> n >> d;
		for (int i = 1;i <= n;i ++) cin >> a[i];
		for (int i = 1;i <= n;i ++) {
			for (int j = i + 1;j <= n;j ++){
				if(check(i,j)) ans ++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}