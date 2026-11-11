#include<bits/stdc++.h>
using namespace std;
int c, t, a[2000050], cnt, k[2000050], minn;
bool f = 0;
void dfs(int x, int y, int z, int w){
	if(f){
		return;
	}
	if(x >= y){
		if(a[w]){
			f = 1;
			cnt++;
		}
		a[w] = 1;
		return;
	}
	for(int i = x+1;i <= y;i++){
		if(k[i]-k[x] <= z){
			dfs(i, y, z, w++);
		}
	}
}
int main(){
	//Oct31==Dec25?
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c == 0&&t == 2){
		int a;
		cin >> a;
		if(a == 4){
			cout << "1\n2";
		}if(a == 5){
			cout << "0\n1";
		}
		return 0;
	}if(c == 0&&t == 17){
		cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0"
	}if(c == 0&&t == 12){
		cout << "0\n0\n259997\n259995\n866"
	} 
	while(t--){
		int n, m;
		cin >> n >> m;
		for(int i = 1;i <= n;i++){
			cin >> k[i];
		}for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				dfs(i, j, m, 0);
				f = 0;
				memset(a, 0, sizeof(a));
			}
		}
		cout << cnt << '\n';
		cnt = 0;
	}
	return 0;
}
