#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll Timetable[100][100] = {0};
int c, n, m, d, q, a[1000], t[100][100] = {0}, k;
ll w[1000];
void findway(int x, int y, int start, int goal, int sum){
	if(Timetable[y][x] == goal){
		sum += (t[y][x] + w[Timetable[y][x]]);
		cout << sum << endl;
		return;
	}
	if(Timetable[y][x] == start){
		sum += (w[Timetable[y][x]] + t[y][x]);
	}
	if(Timetable[y][x] == 0){
		sum += (t[y-1][x]+t[y-1][x+1]);
		y--;
		x++;
	}
	else y++;
	findway(x, y, start, goal, sum);
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		scanf("%d", &k);
		for(int j = 1; j <= k; j++){
			cin >> a[j] >> t[a[j]][i];
			Timetable[a[j]][i] = a[j];
		}
	}
	for(int i = 1; i <= q; i++){
		int x, y, j = 1;
		cin >> x >> y;
		for(; j <= m; j++){
			if(Timetable[y][j] == y) break;
		}
		if(Timetable[x][j] != 0) findway(j, x, x, y, 0);
		else findway(1, x, x, y, 0);
	}
}
		
