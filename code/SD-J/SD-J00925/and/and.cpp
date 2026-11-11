#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[200001] , s[200001];
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int maxn = -1;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(m == 1){
		for(int i = 1;i <= n;i++) if(a[i] > maxn) maxn = a[i];
		cout << maxn;
		return 0; 
	} 
	stable_sort(a + 1, a + 1 + n);
	int ans = -1 , x = a[n];
	int cnt = 0;
	for(int i = n;i >= 1;i--){
		cnt = 0;
		for(int j = i - 1;j >= 1;j--){
			if(a[j] == a[i]) cnt++;
		}
		if(cnt > m){
			ans = cnt;
			if(a[i] > x) x = a[i];
		}
	}
	cout << x;
	return 0;
}
