#include<iostream>
#include<string.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int c, t, n;
ll d;
ll x[6000];
int nxt[6000], lst[6000], a[6000];//a: cha fen
ll dis[6000][6000];
//only do n^2, n < 6000
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	int l, r, mid, cnt;
	ll ans;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		int ptr = 1;
		for(int i = 1; i <= n; i++){
			while(x[ptr] - x[i] <= d && ptr <= n){
				ptr++;
			}
			ptr--;
			nxt[i] = ptr;
		}
		ptr = n;
		for(int i = n; i >= 1; i--){
			while(x[i] - x[ptr] <= d && ptr > 0){
				ptr--;
			}
			ptr++;
			lst[i] = ptr;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j){
					dis[i][j] = 0;
				}else{
					dis[i][j] = INF;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				dis[i][j] = dis[i][max(i, lst[j])] + 1;
				dis[j][i] = dis[i][j];
			}
		}
		ans = 0;
		for(int i = 1; i <= n; i++){
			memset(a, 0, sizeof(a));
			for(int j = i; j < n; j++){
				//find min k for dis(i,k) = dis(i,j) + 1
				l = j + 1, r = n, mid;
				while(l <= r){
					mid = (l + r) / 2;
					if(dis[i][mid] >= dis[i][j] + 1){
						r = mid - 1;
					}else{
						l = mid + 1;
					}
				}
				//l = min k for ...
				//a[l to nxt[j]] += 1
				if(dis[i][l] != dis[i][j] + 1) continue;
				if(l <= nxt[j]){
					a[l]++;
					a[nxt[j] + 1]--;
				}
			}
			cnt = 0;
			for(int j = 1; j <= n; j++){
				cnt += a[j];
				if(cnt == 2 && dis[i][j] < INF - 10){
					//if(t == 3){
					//	cout << '*' << i << ' ' << j << endl;
					//}
					ans++;
				}
			} 
		}
		/*
		if(t == 3){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					cout << dis[i][j] << ' ';
				}
				cout << endl;
			}
		}
		*/
		cout << ans << endl;
	}
	//RP+=INF
	//i want 40pts
	
	return 0;
}
//X X X XXXX
//ohno mow 18:19
//i cant even do n^2
//im not goint to do t4
//maybe 220 pts
//ahhhhhhhh
