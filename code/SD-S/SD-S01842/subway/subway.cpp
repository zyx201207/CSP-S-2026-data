#include<bits/stdc++.h>
using namespace std;
const int maxm = 500050;
const int maxn = 550;
int c,n,m,d,q,x,y,wz[2],nt = 0,mt = 350234;
long long w[maxm],k[maxn],ax[maxn],ay[maxn];
long long a[maxn][maxn],t[maxn][maxn],xz[maxn][maxn] = {0},zx[maxn][maxn] = {0};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i < m;i++){
		cin >> w[i];
	}
	for(int i = 0;i < n;i++){
		cin >> k[i];
		for(int j = 0;j < k[i];j++){
			cin >> a[i][j] >> t[i][j];
			xz[i][j] = 0;
			ax[a[i][j]]++;
		}
	}
	for(int r = 0;r < q;r++){
		nt = 0;
		mt = 3502340;
		cin >> x >> y;
		wz[0] = x;
		int axx = ax[x],dd = 0;
		int sf = 0;
		nt = w[x - 1] + w[y - 1];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < k[i];j++){
				xz[i][j] = 0;
				zx[i][j] = 0;
			}
		}
		while(axx--){
			nt = w[x - 1] + w[y - 1];
			for(int i = 0;i < n;i++){
				for(int j = 0;j < k[i];j++){
					if(a[i][j] == x && xz[i][j] == 0){
						nt += t[i][j];
						xz[i][j] = 1;
						wz[1] = i;
						while(wz[0] != y){
							for(int ii = 0;ii < k[i];ii++){
								if(a[wz[1]][ii] == y){
									nt += t[wz[1]][ii];
									wz[0] = a[wz[1]][ii];
									dd = 1;
									break;
								}
							}
							if(dd == 1){
								break;
							}
							for(int ii = 0;ii < k[wz[1]];ii++){
								if(ax[a[wz[1]][ii]] >= 2){
									sf = 0;
									for(int i1 = 0;i1 < n;i1++){
										for(int j1 = 0;j1 < k[i1];j1++){
											if(a[i1][j1] == a[wz[1]][ii] && i1 != wz[1] && zx[wz[1]][ii] == 0){
												zx[i1][j1] = 1;
												zx[wz[1]][ii] = 1;
												nt += t[wz[1]][ii];
												wz[1] = i1;
												nt += t[i1][j1];
												sf = 1;
												break;
											}
										}
										if(sf == 1){
											break;
										}
									}
									break;
								}
							}
						}
					}
				}
			}
			if(nt <= mt && dd == 1){
				mt = nt;
			}
			dd = 0;
		}
		cout << mt << "\n";
	}
	return 0;
}
