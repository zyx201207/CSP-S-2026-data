#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 5e5 + 10;
const int inf = 0x3f3f3f3f;
int n, m;
int a[maxn];
int shu(int x, int y){
	int sum = 0;
	for (int i = x;i < y;++ i){
		sum += (a[y] - a[i]);
	}
	return sum;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;++ i){
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	int ans = -214748364; 
	for (int i = 2;i <= n;++ i){
		for (int j = 1;j < i;++ j){
			int i_j = i - j + 1;
			//	cout << i_j << ' ' << ans << '\n';
			if (i_j > ans){
				int xx = shu(j, i); 
				//	cout << "ok!" << xx << '\n';
				if (xx <= m){
					//		cout << "yes" << xx << " " << i_j << '\n';
					ans = i_j;	
				}
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}