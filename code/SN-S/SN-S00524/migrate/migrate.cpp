//姓名:陆坦仪
//学校:西安市第三中学 
//考号:SN-S00524
#include<bits/stdc++.h>
using namespace std;
long long c,t,a[200010] = {};
long long ans = 0;
void floyd(int x,int y,int n,int d){
//	cout << x <<"--------->" << y <<":\n";
	if(a[x] + d == a[y])return;
	int o = 0;
	for(int i = x + 1;i < y;i++){
		if(a[i] - a[x] <= d && a[y] - a[i] <= d){
			o++;
//			cout << x << ' ' << i << " " << y << '\n';
//			cout << "o = " << o << '\n';
		}
	}
	if(o == 2){
		ans++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c >= 11 && c <= 12){
		while(t--){
			int n,d;
			cin >> n >> d;
			for(int i = 1;i <= n;i++){
				cin >> a[i];
			}
			int mid;
			for(int i = 1;i <= n;i++){
				//找岛 
				if(a[i] + d >= a[n] && a[i] - d <= a[n]){
					mid = i;
					break;
				}
			}
			cout << min(n - mid,mid) << '\n';
			ans = 0;
		}
	} 
	while(t--){
		int n,d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		for(int i = d;i <= n;i++){
			for(int j = 1;j <= n - i;j++)floyd(j,j + i,n,d);
		}
		cout << ans << '\n';
		ans = 0;
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
