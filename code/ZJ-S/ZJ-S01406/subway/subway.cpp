#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
long long w[500005];
long long t[105][1005],a[105][1005];
long long k[105];
long long x,y,z;
int xx,yy,xxx,yyy;
long long ans;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--){
		cin >> x >> y;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= k[i];j++){
				if(x == a[i][j] && xx == 0){
					xx=i;
					xxx=j;
				}
				if(y == a[i][j] && yy == 0){
					yy=i;
					yyy=j;
				}
			}
		}
		//cout << xx << ' ' << yy;
		if(xx == yy){
			//cout << w[x] << ' ' << t[xx][x] << ' ' << t[yy][y] << ' ' << w[y] << endl;
			ans = w[x] + t[xx][xxx] + t[yy][yyy] + w[y];
		}
		else{
			for(int i = 1;i <= n;i++){
				for(int j = i+1;j <= n;j++){
					for(int g = 1;g <= k[i];g++){
						for(int l = 1;l <= k[i];l++){
							if(a[i][g] == a[j][l]){
								z = t[i][g] + t[j][l];
							}
						}
					}
				}
			}
			//cout << w[x] << ' ' << t[xx][xxx] << ' ' << z << ' ' << t[yy][yyy] << ' ' << w[y] << endl;
			ans = w[x] + t[xx][xxx] + z + t[yy][yyy] + w[y];
		}
		cout << ans << endl;
		ans = 0;
		xx = 0;
		yy = 0;
		z = 0;
	}
	return 0;
}
