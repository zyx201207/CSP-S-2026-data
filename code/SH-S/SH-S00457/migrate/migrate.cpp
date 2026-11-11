#include<bits/stdc++.h>
using namespace std;
int c , t;
int n;
long long d;
struct node{
	int to;
	long long cost;
};
vector<node> ve;
int have_go[310][310];
long long a[2000010];
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> c >> t;
	while(t--){
		long long dis[310][310];
		memset(dis , 0x3f , sizeof(dis));
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(a[j] - a[i] <= d){
					dis[i][j] = 1;
					dis[j][i] = 1;
				}
			}
		}
		for(int k = 1; k <= n; k++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(dis[i][k] + dis[k][j] < dis[i][j]){
						dis[i][j] = dis[i][k] + dis[k][j];
						have_go[i][j] = 1;
					}else if(dis[i][k] + dis[k][j] == dis[i][j]){
//						cout << i << ' ' << k << ' ' << j << endl; 
						have_go[i][j]++;
					}
				}
			}
		}
		long long cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(have_go[i][j] == 2){
					cnt++;
//					cout << i << ' ' << j << ' ' << dis[i][j] << '\n';
				}
			}
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
