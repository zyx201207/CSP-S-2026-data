#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int c,t,a[N],n,f,d[N][N],ff[N][N],ans;
//AK666
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> f;
		ans = 0;
		for(int i = 1;i<=n;i++){
			cin >> a[i];
		}
		memset(d,0x3f,sizeof(d));
		memset(ff,0,sizeof(ff));
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(abs(a[i]-a[j])<=f)d[i][j] = 1;
				if(i == j)d[i][j] == 0;
			}
		}
		for(int k = 1;k<=n;k++){
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n;j++){
					if(d[i][j]>d[i][k]+d[k][j]){
						d[i][j] = d[i][k]+d[k][j];
						if(ff[i][j]!=1)ff[i][j] = 1;
					}else if(d[i][j]==d[i][k]+d[k][j]&&d[i][j]!=0){
						ff[i][j]++;
					}
				}
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(ff[i][j] == 2){
					ans++;
				}
			}
		}
		cout << ans/2 << '\n';
	}
	return 0;
}
