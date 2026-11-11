#include <bits/stdc++.h>
using namespace std; 
long long c , n , m , d , q , w[500005], k[505] , a[505][50005] , t[505][50005] , x[10005] , y[100005] ,s,aa,bb;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c>> n>> m>>d>>q;
	for(int i = 0; i < m; i ++){
		cin >> w[i];
	}
	for(int i = 0; i < n; i ++){
		cin >> k[i];
		for(int j = 0; j < k[i]; j ++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 0; i < q; i ++){
		s=0;
		cin >> x[i]>>y[i];
		x[i]-=1;
		y[i]-=1;
		for(int z = 0; z < n; z ++){
			for(int j = 0; j < k[i]; j ++){
				if(x[i]==a[z][j]){
					aa=z;
				}
				if(y[i]==a[z][j]){
					bb=z;
				}
			}
		}
		if(aa!=bb){
			for(int j =0;j<n;j++){
				for(int z = 0; z < n; z ++){
					if(k[j]=k[z]){
						s=w[x[i]] + t[x[i]][x[i]] + t[x[i]][k[j]-1] + t[k[j]-1][y[j]] + t[y[j]][y[j]] + w[y[i]];
						break;
					}
				}
			}
		} else{
			s=w[x[i]] + t[x[i]][x[i]] + t[x[i]][y[i]]+w[y[i]];
		}
		cout << s << endl;
	}
	
	//16：05感觉像dfs，但我不会写 T_T 
	//16：51死了 QWQ 毁灭吧 
	return 0;
}
