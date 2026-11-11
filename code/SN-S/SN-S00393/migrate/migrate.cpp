#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[2000005];
int n, ans;
ll d;
bool f(int a, int b){
	if (x[b] - x[a] <= d) return 0;
	int now = a, num = 0;
	while(now != b){
		for (int i = b; i > a; i--){
			if (x[i] - x[now] <= d){
				num = x[i] - x[now];
				now = i;
				break;
			}
		}
	}
	if (x[a + 1] - x[a] != d - num) return 0;
	else return 1;
}
void work(){
	ans = 0;
	cin >> n >> d;
	int nn = n;
	for (int i = 0; i < n; i++){
		cin >> x[i];
	}
	for (int i = n - 1; i >= 0; i--){
		if (x[i] - x[i - 1] > d){
			x[i] = 0;
			nn--;
		}
	}
	for (int i = 0; i < nn - 3; i++){
		for (int j = i + 3; j < nn; j++){
			if (f(i,j)) ans++;
		}
	}
	cout << ans << "\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		work();
	}
	return 0;
}
