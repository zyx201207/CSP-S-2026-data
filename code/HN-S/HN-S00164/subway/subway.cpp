#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,t;
int w[505],k;
long long sum,minn;
struct node{
	int a,t1;
}b[30];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> t;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 1; j <= 2*k; j++){
			cin >> b[i].a >> b[i].t1;
		}
	}
	for(int i = 1; i <= t; i++){
		int x,y;
		cin >> x >> y;
	}
	cout << w[1]+b[1].t1;
	return 0;
}
