/*
Maybe 10 pts.

100 + 60 + [24, 50] + [0, 10] = [184, 220] pts
*/
#include<bits/stdc++.h>
#define Hahaha using
#define I namespace
#define AK std
#define IOI ;
#define ll long long
#define N (int)(5e5 + 10)
Hahaha I AK IOI
vector<int> g[N];
int c, n, m;

void work(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
	}
	cout << max(1, (((n + 1) / 2) - m) / 4 + 1) << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int oT_To = 1;
	cin >> c >> oT_To;
	while(oT_To--){
		work();
	}
	return 0;
}
