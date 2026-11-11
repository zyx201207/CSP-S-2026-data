#include<bits/stdc++.h>
using namespace std;

int n;
long long ans;
int a[200005];
char p[200005];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> p[i];
	for(int i = 1, j = n; i <= n, i < j; i++){
		while(a[i]){
			if(i == j) break;
			if(a[i] < a[j]){
				if(p[i] != p[j]) ans += a[i];
				a[j] -= a[i];
				a[i] = 0;
				break;
			}
			if(p[i] != p[j]) ans += a[j];
			a[i] -= a[j];
			a[j] = 0;
			j--;
		}
	}
	cout << ans;
	
	return 0;
}
