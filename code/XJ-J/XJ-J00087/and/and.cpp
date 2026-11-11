#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
struct node{
	int c;
	int b[201];
	int s;
};
node a[200001];
int cmp(node a, node b){
	return a.c < b.c;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	bool flag = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i].c;
		int  k = a[i].c;
		while(k != 0){
			a[i].s++;
			a[i].b[a[i].s] = k % 2;
			k /= 2;
		}
	}
	cout << 1;
	sort(a + 1, a + n + 1, cmp);
	ans = a[n].c;
	for(int j = a[n].s; j >= 1; j--){
		int zong = 0;
		for(int i = n; i >= 1; i--){
			if(a[i].b[j]) zong++;
			ans &= a[i].c;
			if(zong == m){
				cout << ans << "\n";
				return 0;
			}
		}
		ans = a[n - zong].c;
	}
	return 0;
}
