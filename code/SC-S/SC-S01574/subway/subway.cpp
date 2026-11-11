#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int a[505][505],b[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++){
		int x;cin >> x;
		v.push_back(x);
	}
	for(int i = 1 ; i <= n ; i++){
		int k;cin >> k;
		for(int j = 1 ; j <= k ; j++){
			int x,y;cin >> x >> y;
			a[i][j]=x,b[i][j]=y;
		}
	}
	for(int i = 1 ; i <= q ; i++){
		int x,y;cin >> x >> y;
	}
	
	return 0;
}