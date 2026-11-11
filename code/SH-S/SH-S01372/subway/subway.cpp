#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e4+5;
int c,m,n,d,q,w[maxn],a[maxn][maxn],t[maxn][maxn],k[maxn];
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin >> c >>n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	} 
	for(int i = 1;i <= n;i++){
		cin >>k;
		for(int j = 1;j<= k*2;j++) cin >> a[i][j] >>t[i][j]; 
		q[i].push_back({j,1});
		q[j].push_back({i,1});
	}
	
	
	while(q--){
		int x,y;
		cin >> x >>y; 
		int cnt = w[x] + w[y];
		for(int i = x;i <= y;i++){
			for(int j = x;j < y;j++){
				cnt += t[i][j];
			}
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	
}

