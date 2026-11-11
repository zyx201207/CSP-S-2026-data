#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[505];
struct node{
	int a;
	int t;
};
node s[505];
int sum[505][505],id[505];
int dfs(int x,int y,int tm,int d){
	if (x == y){
		return d;	
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++){
			int x,y;
			cin >> x >> y;
			s[i].a = x;s[i].t = y;
			id[x]++;
			sum[x][id[x]] = i;
		}
	}
	cin >> q;
	while(q--){
		int x,int y;
		cin >> x >> y;
		cout << dfs(x,y,tm) << endl;
	}
	return 0;
}
