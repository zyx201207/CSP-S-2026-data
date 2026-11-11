#include<bits/stdc++.h>
using namespace std;

int n, m, sum;
int a[1000005];
int f[1000005];
bool t_f;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio;
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
	}  
	sort(a + 1, a + n + 1);
	sum = a[n] - a[n - 1];
	for (int i = 1; i <= n; i ++){
		f[i] = i * (i - 1) * sum / 2;
	}
	
	for (int i = 1; i <= n; i ++){
		if (f[i] > m){
			cout << i - 1;
			return 0;
		}
	}
	return 0;
}

